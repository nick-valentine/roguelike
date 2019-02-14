#ifndef STATE_PLAYING_H
#define STATE_PLAYING_H

#include <memory>
#include <vector>
#include "../levelPass/levelPass.h"
#include "../objects/level.h"

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
		void generateLevel();
		
		std::unique_ptr<objects::Level> mLevel;
		std::vector<levelPass::ptr> mLevelPasses;
	};
}

#endif // STATE_PLAYING_H