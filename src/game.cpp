#include "game.h"

#include <chrono>
#include <thread>

#include "window/game.h"
#include "state/mainMenu.h"

Game::Game()
{
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);
	mScreenDims = iPoint(maxX, maxY);
	mWin = std::make_unique<window::Game>(iPoint(0, 0), mScreenDims);

	mStateStack.push(new state::MainMenu());

	mPallette.addColor(COLOR_YELLOW, COLOR_BLACK);
	mPallette.addColor(COLOR_RED,    COLOR_BLACK);
}

int Game::run()
{
	refresh();

	mPallette.activate();

	while (true) {
		mWin->render();

		mWin->clear();
		mStateStack.top()->render(mWin);

		int rawInput = mWin->getCh();
		auto input = mKeymap.convert(rawInput);

		Context ctx;
		ctx.input = input;
		ctx.rawInput = rawInput;

		mStateStack.top()->update(&ctx);

		if (mStateStack.top()->shouldClose()) {
			auto oldState = mStateStack.top();
			mStateStack.pop();
			if (mStateStack.size() == 0) {
				return 0;
			}
			mStateStack.top()->recvUp(oldState->passDown());
			delete oldState;
		} else if (mStateStack.top()->nextState() != nullptr) {
			auto newState = mStateStack.top()->nextState();
			auto oldState = mStateStack.top();
			newState->recvDown(oldState->passUp());
			mStateStack.push(newState);
			oldState->clearNextState();
		}
	}
	return 0;
}
