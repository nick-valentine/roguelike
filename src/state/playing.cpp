#include "playing.h"

namespace state
{
	Playing::Playing() : Abstract(), mCamera(iPoint(0, 0))
	{
		mLevelPasses = levelPass::defaultPasses();
		this->generateLevel();
		mLog->info("hello world!");
	}

	void Playing::update(Context *ctx)
	{
		mLevel->update(ctx);
		auto player = mLevel->getPlayer();
		mCamera.moveTo(player->pos());

		switch (ctx->input) {
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