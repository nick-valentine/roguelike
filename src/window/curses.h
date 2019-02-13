#ifndef WINDOW_CURSES_H
#define WINDOW_CURSES_H

#include <curses.h>
#include <memory>

#include "abstract.h"

using namespace utility;

namespace window
{
	class Curses : public Abstract
	{
	public:
		Curses() = delete;
		Curses(iPoint pos, iPoint size);
		virtual ~Curses();

		virtual void putstr(iPoint p, std::string str, int color = 0);
		virtual void put(uint colorPair, uint layer, char c, iPoint p);
		virtual void put(TextElement c, iPoint p);
		virtual void clear();

		virtual void render();
		virtual void resize(iPoint size);
		virtual void move(iPoint to);

		virtual int getCh();

		virtual iPoint pos();
		virtual iPoint size();
	protected:
		static const int getchTimeout = 11;
		
		WINDOW *mWin = nullptr;

		iPoint mPos;
		iPoint mSize;
	};
}

#endif // WINDOW_CURSES_H