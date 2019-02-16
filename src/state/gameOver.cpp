#include "gameOver.h"

#include "playing.h"

namespace state
{
	GameOver::GameOver() : Abstract()
	{
		mNextState = new Playing();
	}

	void GameOver::update(Context *ctx)
	{
		switch (ctx->input) {
		case Input::ESCAPE:
			mShouldClose = true;
			return;
		default:
			break;
		}
	}

	void GameOver::render(window::ptr &win)
	{
		auto s = win->size();
		win->putstr(iPoint(s.x / 2, s.y / 2), "you have died!");
	}
}