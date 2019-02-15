#include "playing.h"

#include "fight.h"

namespace state
{
	Playing::Playing() : Abstract(), mCamera(iPoint(0, 0))
	{
		mLevelPasses = levelPass::defaultPasses();
		this->generateLevel();
		mPlayerStats = objects::attributes::basePlayer(1);
		mLog->info("hello world!");
	}

	void Playing::update(Context *ctx)
	{
		if (mRecvMsgUp == 1) {
			// player killed monster
			mLevel->killEntity(mFightingMonster);
			mFightingMonster = -1;
		}
		if (mRecvMsgUp == 2) {
			// player died
			mShouldClose = true;
			return;
		}
		mRecvMsgUp = 0;

		mLevel->update(ctx);
		auto player = mLevel->getPlayer();
		mCamera.moveTo(player->pos());

		auto c = mLevel->checkCollision();
		if (c.first != -1) {
			auto first = mLevel->getEntity(c.first);
			auto second = mLevel->getEntity(c.second);
			auto player = mLevel->getPlayer();
			const objects::Entity* notPlayer = nullptr;
			mLog->warn("%s ran into a %s!", first->name.c_str(), second->name.c_str());
			if (first == player || second == player) {
				if (first != player) {
					notPlayer = first;
					mFightingMonster = c.first;
				} else {
					notPlayer = second;
					mFightingMonster = c.second;
				}

				mLog->warn("you ran into a %s!", notPlayer->name.c_str());
				mNextState = new Fight(player, &mPlayerStats, notPlayer);
				return;
			}
		}

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