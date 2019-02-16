#ifndef STATE_GAME_OVER_H
#define STATE_GAME_OVER_H

#include "abstract.h"
#include "../component/menu.h"

namespace state
{
	class GameOver : public Abstract
	{
	public:
		GameOver();
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
	};
}

#endif // STATE_GAME_OVER_H