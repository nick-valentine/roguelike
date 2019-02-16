#ifndef STATE_PLAYING_H
#define STATE_PLAYING_H

#include <memory>
#include <vector>
#include <stack>
#include "../levelPass/levelPass.h"
#include "../objects/level.h"
#include "../objects/entityAttribute.h"
#include "../objects/itemFuncs.h"
#include "../objects/item.h"
#include "../camera.h"

#include "abstract.h"

namespace state
{
	class Playing : public Abstract
	{
	public:
		Playing();
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
		using lvl = std::unique_ptr<objects::Level>;
		void generateLevel();
		
		objects::EntityAttribute mPlayerStats;

		Camera mCamera;
		std::stack<lvl> mLevel;
		std::vector<levelPass::ptr> mLevelPasses;

		int mFightingMonster = -1;
	};
}

#endif // STATE_PLAYING_H