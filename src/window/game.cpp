#include "game.h"

namespace window
{
	Game::Game(iPoint pos, iPoint size) : Curses(pos, size)
	{
		this->resize(size);
	}

	void Game::resize(iPoint size)
	{
		TextElement templ;
		templ.colorPair = 0;
		templ.layer = 0;
		templ.c = ' ';

		mScreenBuffer.clear();
		for (int i = 0; i < size.y; ++i) {
			mScreenBuffer.push_back(std::vector<TextElement>());
			for (int j = 0; j < size.x; ++j) {
				mScreenBuffer[i].push_back(templ);
			}
		}
		Curses::resize(size);
	}

	void Game::putstr(iPoint p, std::string str, int color) 
	{
		int counter = 0;
		for (const auto &i : str) {
			this->put(color, 999, i, iPoint(p.x + counter++, p.y));
		}
	}

	void Game::put(uint colorPair, uint layer, char c, iPoint p)
	{
		TextElement temp;
		temp.colorPair = colorPair;
		temp.layer = layer;
		temp.c = c;
		this->put(temp, p);
	}

	void Game::put(TextElement c, iPoint p)
	{
		if (p.x < mSize.x && p.x > 0  && p.y < mSize.y && p.y > 0) {
			if (c.layer > mScreenBuffer[p.y][p.x].layer) {
				mScreenBuffer[p.y][p.x] = c;
			}
		}
	}

	void Game::clear()
	{
		TextElement templ;
		templ.colorPair = 0;
		templ.layer = 0;
		templ.c = ' ';

		for (auto &i : mScreenBuffer) {
			for (auto &j : i) {
				j = templ;
			}
		}
	}

	void Game::render()
	{
		uint lastColorPair = 1;
		wattrset(mWin, COLOR_PAIR(1));
		wmove(mWin, 0, 0);
		int rowCount = 0;
		for (auto &i : mScreenBuffer) {
			for (auto &j : i) {
				if (j.colorPair != lastColorPair) {
					wattrset(mWin, COLOR_PAIR(j.colorPair));
					lastColorPair = j.colorPair;
				}
				waddch(mWin, j.c);
			}
			rowCount++;
			wmove(mWin, rowCount, 0);
		}
		Curses::render();
	}
}