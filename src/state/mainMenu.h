#ifndef STATE_MAIN_MENU_H
#define STATE_MAIN_MENU_H

#include "abstract.h"
#include "../component/menu.h"

namespace state
{
	class MainMenu : public Abstract
	{
	public:
		MainMenu();
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
		component::Menu mMenu;
	};
}

#endif // STATE_MAIN_MENU_H