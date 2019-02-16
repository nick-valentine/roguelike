#include "inventoryItem.h"

namespace state
{
	InventoryItem::InventoryItem(objects::EntityAttribute *playerStats, std::string name) : Abstract(), mPlayerStats(playerStats), mName(name)
	{
		std::vector<std::string> options;
		options.push_back("throw away");
		options.push_back("use");
		options.push_back("back");
		mMenu = component::Menu(mName, options, iPoint(1, 1), iPoint(20, 20));
	}

	void InventoryItem::update(Context *ctx)
	{
		int result = mMenu.update(ctx);
		switch (result) {
		case -1:
			return;
		case -2:
			mShouldClose = true;
			return;
		case 0:
			remove();
			mShouldClose = true;
			break;
		case 1:
			mShouldClose = use();
			break;
		case 2:
			mShouldClose = true;
			break;
		}
	}

	void InventoryItem::render(window::ptr &win)
	{
		mMenu.setDims(iPoint(1, 1), win->size());
		mMenu.render(win);
	}

	int InventoryItem::locateArmor()
	{
		if (mName.find("equiped: ") != std::string::npos) {
			auto name = mName.substr(9);
			for (int i = 0; i < mPlayerStats->armor.size(); i++) {
				if (mPlayerStats->armor[i].name == name) {
					return i;
				}
			}
		}
		return -1;
	}

	int InventoryItem::locateWeapon()
	{
		if (mName.find("weapon: ") != std::string::npos) {
			auto name = mName.substr(8);
			for (int i = 0; i < mPlayerStats->weapons.size(); i++) {
				if (mPlayerStats->weapons[i].name == name) {
					return i;
				}
			}
		}
		return -1;
	}

	int InventoryItem::locateInventory()
	{
		auto name = mName;
		for (int i = 0; i < mPlayerStats->inventory.size(); i++) {
			if (mPlayerStats->inventory[i].name == name) {
				return i;
			}
		}
		return -1;
	}

	bool InventoryItem::use()
	{
		auto id = locateWeapon();
		if (id != -1) {
			mLog->info("you wave the %s through the air!", mPlayerStats->weapons[id].name.c_str());
			return false;
		}

		id = locateArmor();
		if (id != -1) {
			mLog->info("you take off the %s", mPlayerStats->armor[id].name.c_str());
			mPlayerStats->dequip(id);
			return true;
		}

		id = locateInventory();
		if (id != -1) {
			if (mPlayerStats->inventory[id].armor) {
				mLog->info("you put on the %s", mPlayerStats->inventory[id].name.c_str());
				mPlayerStats->equip(id);
				return true;
			} else if(mPlayerStats->inventory[id].useable) {
				mLog->info("you use the %s", mPlayerStats->inventory[id].name.c_str());
				auto usedUp = mPlayerStats->inventory[id].use(mPlayerStats);
				if (usedUp) {
					mPlayerStats->inventory[id] = mPlayerStats->inventory[mPlayerStats->inventory.size() - 1];
					mPlayerStats->inventory.pop_back();
				}
				return usedUp;
			}
		}
	}

	void InventoryItem::remove()
	{
		mLog->info("you throw away the %s", mName.c_str());
		auto id = locateWeapon();
		if (id != -1) {
			mPlayerStats->weapons[id] = mPlayerStats->weapons[mPlayerStats->weapons.size() - 1];
			mPlayerStats->weapons.pop_back();
			return;
		}

		id = locateArmor();
		if (id != -1) {
			mPlayerStats->armor[id] = mPlayerStats->armor[mPlayerStats->armor.size() - 1];
			mPlayerStats->armor.pop_back();
			return;
		}

		id = locateInventory();
		if (id != -1) {
			mPlayerStats->inventory[id] = mPlayerStats->inventory[mPlayerStats->inventory.size() - 1];
			mPlayerStats->inventory.pop_back();
			return;
		}
	}
}