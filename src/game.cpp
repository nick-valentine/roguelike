#include "game.h"

#include "window/game.h"

Game::Game()
{
	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);
	mScreenDims = iPoint(maxX, maxY);
	mWin = std::make_unique<window::Game>(iPoint(0, 0), mScreenDims);

	mLevelPasses = levelPass::defaultPasses();

	this->generateLevel();

	mPallette.addColor(COLOR_YELLOW, COLOR_BLACK);
	mPallette.addColor(COLOR_RED,    COLOR_BLACK);
}

int Game::run()
{
	mLevel->draw(mWin);
	mPallette.activate();
	mWin->render();
}

void Game::generateLevel()
{
	mLevel = std::make_unique<objects::Level>(mScreenDims);

	for (const auto &i : mLevelPasses) {
		i->execute(*mLevel);
	}
}