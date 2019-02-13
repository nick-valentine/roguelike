#include "curses.h"

namespace window 
{
	Curses::Curses(iPoint pos, iPoint size) : 
		Abstract(),
		mPos(pos),
		mSize(size)
	{
		mWin = newwin(mSize.y, mSize.x, mPos.y, mPos.x);
		keypad(mWin, true);
	}

	Curses::~Curses()
	{
		if (mWin != nullptr) {
			delwin(mWin);
			mWin = nullptr;
		}
	}

	void Curses::putstr(iPoint p, std::string str, int color)
	{
		wattrset(mWin, COLOR_PAIR(color));
		wmove(mWin, p.y, p.x);
		for (const auto &i : str) {
			waddch(mWin, i);
		}
		wattrset(mWin, COLOR_PAIR(0));
	}

	void Curses::put(uint colorPair, uint layer, char c, iPoint p)
	{
		wattrset(mWin, COLOR_PAIR(colorPair));
		wmove(mWin, p.y, p.x);
		waddch(mWin, c);
		wattrset(mWin, COLOR_PAIR(0));
	}

	void Curses::put(TextElement c, iPoint p)
	{
		this->put(c.colorPair, c.layer, c.c, p);
	}

	void Curses::clear()
	{
		werase(mWin);
	}

	void Curses::render()
	{
		wborder(mWin, 0, 0, 0, 0, 0, 0, 0, 0);
		wrefresh(mWin);
	}

	void Curses::resize(iPoint size)
	{
		mSize = size;
		mvwin(mWin, mSize.y, mSize.x);
	}

	void Curses::move(iPoint to)
	{
		mPos = to;
		mvwin(mWin, mPos.y, mPos.x);
	}

	int Curses::getCh()
	{
		wtimeout(mWin, Curses::getchTimeout);
		return wgetch(mWin);
	}

	iPoint Curses::pos()
	{
		return mPos;
	}

	iPoint Curses::size()
	{
		return mSize;
	}
}