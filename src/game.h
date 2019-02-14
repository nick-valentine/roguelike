#ifndef GAME_H
#define GAME_H

#include <memory>
#include <stack>

#include "utility/colorPallette.h"
#include "state/abstract.h"
#include "window/abstract.h"
#include "keyMap.h"

using namespace utility;

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

	Keymap mKeymap;

	iPoint mScreenDims = iPoint(0,0);
	std::stack<state::Abstract *> mStateStack;
};

#endif //GAME_H