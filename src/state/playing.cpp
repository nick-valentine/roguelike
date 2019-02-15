#include "playing.h"

namespace state
{
	Playing::Playing() : Abstract(), mCamera(iPoint(0, 0))
	{
		mLevelPasses = levelPass::defaultPasses();
		this->generateLevel();
		mLog->info("hello world!");
		mLevel->setPlayer(objects::make_player(iPoint(0,0)));
	}

	void Playing::update(Context *ctx)
	{
		mLevel->update(ctx);
		auto player = mLevel->getPlayer();
		mLog->info("player is at (%i %i)", player->pos().x, player->pos().y);
		mCamera.moveTo(player->pos());

		switch (ctx->input) {
		// case Input::UP:
		// 	mCamera.move(iPoint(0, -1));
		// 	break;
		// case Input::DOWN:
		// 	mCamera.move(iPoint(0, 1));
		// 	break;
		// case Input::LEFT:
		// 	mCamera.move(iPoint(-1, 0));
		// 	break;
		// case Input::RIGHT:
		// 	mCamera.move(iPoint(1, 0));
		// 	break;
		case Input::ESCAPE:
			mShouldClose = true;
			return;
		default:
			break;
		}
	}

	void Playing::render(window::ptr &win)
	{
		mCamera.render(win, mLevel);
	}

	void Playing::generateLevel()
	{
		mLevel = std::make_unique<objects::Level>(iPoint(200, 100));

		for (const auto &i : mLevelPasses) {
			i->execute(*mLevel);
		}
	}
}