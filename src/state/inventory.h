#ifndef STATE_INVENTORY_H
#define STATE_INVENTORY_H

#include <vector>
#include <string>

#include "abstract.h"
#include "../component/menu.h"
#include "../objects/entityAttribute.h"

namespace state
{
	class Inventory : public Abstract
	{
	public:
		Inventory(objects::EntityAttribute *playerStats) : mPlayerStats(playerStats) { fill(); };

		void update(Context *ctx);
		void render(window::ptr &win);
		virtual void recvUp(int msg);
	private:
		void fill();
		component::Menu mMenu;
		std::vector<std::string> mOptions;
		objects::EntityAttribute *mPlayerStats;
	};
}

#endif // STATE_INVENTORY_H