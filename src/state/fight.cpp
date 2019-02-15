#include "fight.h"

namespace state
{
	Fight::Fight(const objects::Entity *player, const objects::Entity *other) : Abstract(), mPlayer(player), mOther(other)
	{
		std::vector<std::string> options;
		options.push_back("Punch");
		options.push_back("Run");
		mActionMenu = component::Menu("What do?", options, iPoint(1, 1), iPoint(40, 40));
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
			break;
		case 1:
			mLog->info("you ran");
			break;
		default:
			break;
		}
	}

	void Fight::render(window::ptr &win)
	{
		mActionMenu.render(win);
	}
}