#ifndef GAME_H
#define GAME_H

#include <memory>

#include "window/abstract.h"
#include "objects/level.h"
#include "levelPass/levelPass.h"

class Game
{
public:
	Game();
	~Game() = default;

	int run();

	void generateLevel();
private:
	window::ptr mWin = nullptr;

	ColorPallette mPallette;
	std::unique_ptr<objects::Level> mLevel;
	std::vector<levelPass::ptr> mLevelPasses;

	iPoint mScreenDims = iPoint(0,0);
};

#endif //GAME_H