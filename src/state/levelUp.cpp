#include "levelUp.h"

namespace state
{
	LevelUp::LevelUp(objects::EntityAttribute *playerStats) : mPlayerStats(playerStats)
	{
		std::vector<std::string> options;
		options.push_back("health");
		options.push_back("strength");
		options.push_back("constitution");
		options.push_back("dexterity");
		options.push_back("agility");
		options.push_back("magicka");
		mMenu = component::Menu("You leveled up! What would you like to improve?", options, iPoint(1, 1), iPoint(20, 20));
	}

	void LevelUp::update(Context *ctx)
	{
		int result = mMenu.update(ctx);
		switch (result) {
		case -1:
			return;
		case -2:
			mLog->info("you really should improve something");
			return;
		case 0:
			mPlayerStats->health+=5;
			mPlayerStats->maxHealth+=5;
			break;
		case 1:
			mPlayerStats->strength++;
			break;
		case 2:
			mPlayerStats->constitution++;
			break;
		case 3:
			mPlayerStats->dexterity++;
			break;
		case 4:
			mPlayerStats->agility++;
			break;
		case 5:
			mPlayerStats->magicka++;
		default:
			break;
		}

		mShouldClose = true;
	}

	void LevelUp::render(window::ptr &win)
	{
		mMenu.setDims(iPoint(1, 1), win->size());
		mMenu.render(win);
	}
}