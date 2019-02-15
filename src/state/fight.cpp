#include "fight.h"

#include <random>

namespace state
{
	Fight::Fight(const objects::Entity *player, objects::EntityAttribute *playerStats, const objects::Entity *other) : 
		Abstract(), mPlayer(player), mPlayerStats(playerStats), mOther(other)
	{
		std::vector<std::string> options;
		options.push_back("Punch");
		options.push_back("Run");
		mActionMenu = component::Menu("What do?", options, iPoint(1, 1), iPoint(40, 40));

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
			mLog->info("you punched");
			attack(mOther->name, 0, mPlayerStats, &mOtherStats);
			reportTurn();
			break;
		case 1:
			mLog->info("you ran");
			reportTurn();
			break;
		default:
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

	void Fight::attack(std::string attackeeName, int weapon, objects::EntityAttribute *attacker, objects::EntityAttribute *attackee)
	{
		int weaponDamage = 1;
		damageType d;
		d.physical = true;
		if (weapon != 0) {
			// look into inventory
		}
		int damage = weaponDamage * (attacker->strength * d.physical) * (attacker->magicka * d.magicka);
		damage -= (d.physical * attackee->constitution) + (d.magicka * attackee->magicka);
		if (damage <= 0) {
			damage = 1;
		}

		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> dist(0, attacker->dexterity);

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
