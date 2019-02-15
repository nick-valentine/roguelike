#include "game.h"

#include <chrono>
#include <thread>

#include "window/game.h"
#include "window/log.h"
#include "state/mainMenu.h"

Game::Game()
{
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);
	mScreenDims = iPoint(maxX, maxY);
	auto gameScreenDims = iPoint(maxX, maxY *  0.8);
	gameWin = std::make_unique<window::Game>(iPoint(0, 0), gameScreenDims);
	auto lWin = std::make_unique<window::Log>(iPoint(0, gameScreenDims.y), iPoint(mScreenDims.x, mScreenDims.y - gameScreenDims.y));
	mLogger = lWin->log();
	logWin = std::move(lWin);

	mLogger->warn("goodbye");

	mStateStack.push(new state::MainMenu());
	mStateStack.top()->setLogger(mLogger);

	mPallette.addColor(COLOR_GREEN,  COLOR_BLACK);
	mPallette.addColor(COLOR_WHITE,  COLOR_BLACK);
	mPallette.addColor(COLOR_YELLOW, COLOR_BLACK);
	mPallette.addColor(COLOR_RED,    COLOR_BLACK);
	mPallette.addColor(COLOR_WHITE,  COLOR_BLACK);
	mPallette.addColor(COLOR_GREEN,  COLOR_BLACK);
	mPallette.addColor(COLOR_YELLOW, COLOR_BLACK);
	mPallette.addColor(COLOR_RED,    COLOR_BLACK);
}

int Game::run()
{
	refresh();

	mPallette.activate();

	while (true) {
		gameWin->render();
		logWin->render();

		gameWin->clear();
		mStateStack.top()->render(gameWin);

		int rawInput = gameWin->getCh();
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
			mStateStack.top()->setLogger(mLogger);
			oldState->clearNextState();
		}
	}
	return 0;
}
