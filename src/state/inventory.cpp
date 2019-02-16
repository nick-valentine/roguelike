#include "inventory.h"

#include "inventoryItem.h"

namespace state
{
	void Inventory::update(Context *ctx)
	{
		switch (ctx->input) {
		case Input::ESCAPE:
			mShouldClose = true;
			return;
		default:
			break;
		}
		
		int result = mMenu.update(ctx);
		switch (result) {
		case -1:
			return;
		case -2:
			mShouldClose = true;
			return;
		default:
			mLog->info("%s selected", mOptions[result].c_str());
			mNextState = new InventoryItem(mPlayerStats, mOptions[result]);
		}
	}

	void Inventory::render(window::ptr &win)
	{
		mMenu.setDims(iPoint(1, 1), win->size());
		mMenu.render(win);
	}

	void Inventory::recvUp(int msg)
	{
		fill();
	}

	void Inventory::fill()
	{
		mOptions.clear();
		for (const auto &i : mPlayerStats->weapons) {
			mOptions.push_back("weapon: " + i.name);
		}
		for (const auto &i : mPlayerStats->armor) {
			mOptions.push_back("equiped: " + i.name);
		}
		for (const auto &i : mPlayerStats->inventory) {
			mOptions.push_back(i.name);
		}
		mMenu = component::Menu("Inventory", mOptions, iPoint(1, 1), iPoint(20, 20));
	}
}