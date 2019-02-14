#ifndef COMPONENT_MENU_H
#define COMPONENT_MENU_H

#include <vector>
#include <string>
#include <algorithm>

#include "../utility/point.h"
#include "../window/abstract.h"
#include "../context.h"

namespace component
{
	class Menu
	{
	public:
		Menu() = default;
		Menu(std::string head, std::vector<std::string> options, iPoint pos, iPoint size);

		void render(window::ptr &win);
		int update(Context *ctx);
		void setDims(iPoint pos, iPoint size);
	private:
		void drawBorder(window::ptr &win);
		void drawBar(window::ptr &win, iPoint pos, int width);
		void drawPipe(window::ptr &win, iPoint pos, int height);

		std::string mHead;
		std::vector<std::string> mOptions;
		iPoint mPos = iPoint(0,0);
		iPoint mSize = iPoint(0,0);
		int mSelected = 0;
	};
}

#endif // COMPONENT_MENU_H