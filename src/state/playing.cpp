#include "playing.h"

#include "fight.h"
#include "levelUp.h"
#include "inventory.h"
#include "../objects/tile.h"

namespace state
{
	Playing::Playing() : Abstract(), mCamera(iPoint(0, 0))
	{
		this->generateLevel();
		mPlayerStats = objects::attributes::basePlayer(1);
		
		objects::createMapping();
	}

	void Playing::update(Context *ctx)
	{
		if (mRecvMsgUp == 1) {
			// player killed monster
			mLevel.top()->killEntity(mFightingMonster);
			mFightingMonster = -1;
			if (mPlayerStats.exp > mPlayerStats.level * mPlayerStats.level) {
				mPlayerStats.level++;
				mPlayerStats.exp = 0;
				mNextState = new LevelUp(&mPlayerStats);
				return;
			}
		} else if (mRecvMsgUp == 2) {
			// player died
			mShouldClose = true;
			return;
		} else if (mRecvMsgUp == 3) {
			// player ran
			mLevel.top()->bumpPlayer(20);
			mFightingMonster = -1;
		}
		mRecvMsgUp = 0;

		mLevel.top()->update(ctx);
		auto player = mLevel.top()->getPlayer();
		auto pos = player->pos();
		mCamera.moveTo(pos);

		if (mLevel.top()->get(pos).name() == objects::TileName::UpStairs) {
			if (mLevel.size() > 1) {
				mLevel.pop();
				mLevel.top()->bumpPlayer(1);
				return;	
			}
			mLog->info("leaving so soon?");
		} else if (mLevel.top()->get(pos).name() == objects::TileName::DownStairs) {
			this->generateLevel();
			mLog->info("going down into floor %i", mLevel.size());
		} else if (mLevel.top()->get(pos).name() == objects::TileName::Treasure) {
			auto i = objects::items::loot(mLevel.size());
			mLog->info("You found a chest, it contained a %s", i.name.c_str());
			mPlayerStats.award(i);
			mLevel.top()->set(pos, objects::Tile(objects::TileName::Empty));
		}

		auto c = mLevel.top()->checkCollision();
		if (c.first != -1) {
			auto first = mLevel.top()->getEntity(c.first);
			auto second = mLevel.top()->getEntity(c.second);
			auto player = mLevel.top()->getPlayer();
			const objects::Entity* notPlayer = nullptr;
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
		case Input::SELECT:
			mNextState = new Inventory(&mPlayerStats);
			return;
		default:
			break;
		}
	}

	void Playing::render(window::ptr &win)
	{
		mCamera.render(win, mLevel.top());
	}

	void Playing::generateLevel()
	{
		mLevelPasses = levelPass::defaultPasses(mLevel.size() + 1);
		mLevel.push(std::make_unique<objects::Level>(iPoint(200 + (mLevel.size() * 10), 100 + (mLevel.size() * 10))));

		for (const auto &i : mLevelPasses) {
			i->execute(*(mLevel.top()));
		}
	}
}