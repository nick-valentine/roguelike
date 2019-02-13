#include "game.h"

#include "window/game.h"

Game::Game()
{
	mWin = std::make_unique<window::Game>(iPoint(0, 0), iPoint(100, 10));
}

int Game::run()
{
	mWin->putstr(iPoint(1,1), "hello, world", 0);
	mWin->render();
}