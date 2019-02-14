#include "level.h"


#include <iostream>

namespace objects 
{
	Level::Level(iPoint size) : mSize(size)
	{
		for (int i = 0; i < mSize.x; i++) {
			mLand.push_back(std::vector<Tile>());
			for (int j = 0; j < mSize.y; j++) {
				mLand[i].push_back(Tile(TileName::Wall));
			}
		}
	}

	void Level::draw(window::ptr &win)
	{
		for(int i = 1; i < mLand.size(); ++i) {
			for (int j = 1; j < mLand[i].size(); ++j) {
				mLand[i][j].drawAt(win, iPoint(i,j));
			}
		}
	}

	iPoint Level::size()
	{
		return mSize;
	}

	Tile Level::get(iPoint at)
	{
		return mLand[at.x][at.y];
	}

	void Level::set(iPoint at, Tile t)
	{
		mLand[at.x][at.y] = t;
	}
}