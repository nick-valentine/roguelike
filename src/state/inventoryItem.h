#ifndef STATE_INVENTORY_ITEM_H
#define STATE_INVENTORY_ITEM_H

#include <vector>
#include <string>

#include "abstract.h"
#include "../component/menu.h"
#include "../objects/entityAttribute.h"

namespace state
{
	class InventoryItem : public Abstract
	{
	public:
		InventoryItem(objects::EntityAttribute *playerStats, std::string name);
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
		int locateArmor();
		int locateWeapon();
		int locateInventory();
		void use();
		component::Menu mMenu;
		objects::EntityAttribute *mPlayerStats;
		std::string mName;
	};
}

#endif //STATE_INVENTORY_ITEM_H