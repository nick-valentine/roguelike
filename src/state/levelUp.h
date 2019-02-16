#ifndef STATE_LEVEL_UP_H
#define STATE_LEVEL_UP_H

#include <vector>
#include <string>

#include "abstract.h"
#include "../component/menu.h"
#include "../objects/entityAttribute.h"

namespace state
{
	class LevelUp : public Abstract
	{
	public:
		LevelUp(objects::EntityAttribute *playerStats);
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
		component::Menu mMenu;
		objects::EntityAttribute *mPlayerStats;
	};
}

#endif //STATE_LEVEL_UP_H