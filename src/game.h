#ifndef GAME_H
#define GAME_H

#include <memory>

#include "window/abstract.h"

class Game
{
public:
	Game();
	~Game() = default;

	int run();
private:
	std::unique_ptr<window::Abstract> mWin = nullptr;

	int mScreenHeight = 0;
	int mScreenWidth = 0;
};

#endif //GAME_H