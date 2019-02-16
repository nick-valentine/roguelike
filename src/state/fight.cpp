#include "fight.h"

#include <random>

#define LOOT_CHANCE 5

namespace state
{
	Fight::Fight(const objects::Entity *player, objects::EntityAttribute *playerStats, const objects::Entity *other) : 
		Abstract(), mPlayer(player), mPlayerStats(playerStats), mOther(other)
	{
		mOptions.push_back("Run");
		for (const auto &i : mPlayerStats->weapons) {
			mOptions.push_back(i.name);
		}
		mActionMenu = component::Menu("What do?", mOptions, iPoint(1, 1), iPoint(40, 40));

		mOtherStats = other->genAttributes(mPlayerStats->level);

		mLog->info("you have %i health", mPlayerStats->health);
	}

	void Fight::update(Context *ctx)
	{
		int result = mActionMenu.update(ctx);
		switch (result) {
		case -1:
			break;
		case -2:
			break;
		case 0:
			mLog->info("you attempt to run");
			reportTurn();
			break;
		default:
			doTurn(result);
			break;
		}

		switch (ctx->input) {
		case Input::ESCAPE:
			mLog->info("you can not escape that easily!");
			return;
		default:
			break;
		}

		if (mOtherStats.health <= 0) {
			mLog->info("you killed %s", mOther->name.c_str());
			mPlayerStats->exp += mOtherStats.level * 5;
			
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_int_distribution<int> lootChance(0, LOOT_CHANCE);
			if (lootChance(mt) == 1) {
				auto i = objects::items::loot(mOtherStats.level);
				mLog->info("%s dropped a %s", mOther->name.c_str(), i.name.c_str());
				mPlayerStats->award(i);
			}

			mMsgDown = 1;
			mShouldClose = true;
			return;
		}

		if (mPlayerStats->health <= 0) {
			mLog->warn("you have died");
			mMsgDown = 2;
			mShouldClose = true;
			return;
		}
	}

	void Fight::render(window::ptr &win)
	{
		mActionMenu.setDims(iPoint(1, 1), win->size());
		mActionMenu.render(win);
	}

	void Fight::doTurn(int weapon)
	{
		mLog->info("you attack with %s", mOptions[weapon].c_str());
		attack(mOther->name, weapon, mPlayerStats, &mOtherStats);

		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> dist(0, mOtherStats.weapons.size() - 1);
		int enemyWeapon = dist(mt);
		mLog->info("%s attacks with %s", mOther->name.c_str(), mOtherStats.weapons[enemyWeapon].name.c_str());
		attack(mPlayer->name, enemyWeapon, &mOtherStats, mPlayerStats);
		reportTurn();
	}

	void Fight::attack(std::string attackeeName, int weapon, objects::EntityAttribute *attacker, objects::EntityAttribute *attackee)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> critChance(0, 100);

		int weaponDamage = 1;
		int dexBonus = 0;
		damageType d;
		d.physical = true;
		if (weapon != 0) {
			weapon-=1;
			d.magicka = false;
			d.physical = false;
			int str = attacker->weapons[weapon].strength;
			int mag = attacker->weapons[weapon].magicka;
			dexBonus = attacker->weapons[weapon].dexterity;
			if (str != 0) {
				d.physical = true;
			}
			if (mag != 0) {
				d.magicka = true;
			}
			weaponDamage = str + mag;
		}
		int damage = weaponDamage + (attacker->strength * d.physical) + (attacker->magicka * d.magicka);
		if (critChance(mt) == 1) {
			damage *= 2;
		}
		damage -= (d.physical * attackee->constitution) + (d.magicka * attackee->magicka);
		for (const auto &i : attackee->armor) {
			damage -= (d.physical * i.constitution) + (d.magicka * i.magicka);
		}
		if (damage <= 0) {
			damage = 1;
		}

		std::uniform_int_distribution<int> dist(0, attacker->dexterity + dexBonus);

		if (dist(mt) < attackee->agility) {
			mLog->info("%s dodged the attack", attackeeName.c_str());
			return;
		}

		mLog->info("%s took %d damage", attackeeName.c_str(), damage);
		attackee->health -= damage;
		return;
	}

	void Fight::reportTurn()
	{
		reportEnemy();
		reportSelf();
	}

	void Fight::reportEnemy()
	{
		float percentage = (float)mOtherStats.health / (float)mOtherStats.maxHealth;
		if (percentage > 0.8f) {
			mLog->info("%s looks healthy", mOther->name.c_str());
			return;
		}
		if (percentage > 0.6f) {
			mLog->info("%s has some scratches", mOther->name.c_str());
			return;
		}
		if (percentage > 0.4f) {
			mLog->info("%s is bleeding quite a bit", mOther->name.c_str());
			return;
		}
		if (percentage > 0.2f) {
			mLog->info("%s needs some serious medical attention", mOther->name.c_str());
			return;
		}
		if (percentage > 0.0f) {
			mLog->info("%s is on death's door", mOther->name.c_str());
			return;
		}
		if (percentage <= 0.f) {
			mLog->info("%s died", mOther->name.c_str());
			return;
		}
	}

	void Fight::reportSelf()
	{
		float percentage = (float)mPlayerStats->health / (float)mPlayerStats->health;
		if (percentage > 0.8) {
			mLog->info("you have %i health", mPlayerStats->health);
			return;
		}
		mLog->warn("you have %i health", mPlayerStats->health);
	}
}
