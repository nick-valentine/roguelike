#include "playing.h"

namespace state
{
	Playing::Playing() : Abstract()
	{
		mLevelPasses = levelPass::defaultPasses();
		this->generateLevel();
	}

	void Playing::update(Context *ctx)
	{

	}

	void Playing::render(window::ptr &win)
	{
		mLevel->draw(win);
	}

	void Playing::generateLevel()
	{
		mLevel = std::make_unique<objects::Level>(iPoint(50, 50));

		for (const auto &i : mLevelPasses) {
			i->execute(*mLevel);
		}
	}
}