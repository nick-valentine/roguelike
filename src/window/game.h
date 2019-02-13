#ifndef WINDOW_GAME_H
#define WINDOW_GAME_H

#include <curses.h>
#include <vector>

#include "curses.h"
#include "utility.h"

namespace window
{
	class Game : public Curses
	{
	public:
		Game(iPoint pos, iPoint size);

		virtual void resize(iPoint size);
		virtual void putstr(iPoint p, std::string str, int color);
		virtual void put(uint colorPair, uint layer, char c, iPoint p);
		virtual void put(TextElement c, iPoint p);

		virtual void clear();
		virtual void render();
	private:
		std::vector< std::vector< TextElement > > mScreenBuffer;
	};
}

#endif // WINDOW_GAME_H