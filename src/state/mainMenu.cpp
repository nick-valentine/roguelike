#include "mainMenu.h"

#include "playing.h"

namespace state
{
	MainMenu::MainMenu() : Abstract()
	{
		std::vector<std::string> options;
		options.push_back("Play Game");
		options.push_back("Quit");
		mMenu = component::Menu("What do?", options, iPoint(10, 10), iPoint(20, 20));
	}

	void MainMenu::update(Context *ctx)
	{
		int result = mMenu.update(ctx);
		switch (result) {
		case -1:
			break;
		case -2:
			mShouldClose = true;
			mMsgDown = -1;
			break;
		case 0:
			mNextState = new Playing();
			break;
		case 1:
			mShouldClose = true;
			mMsgDown = -1;
		default:
			break;
		}
	}

	void MainMenu::render(window::ptr &win)
	{
		mMenu.render(win);
	}
}