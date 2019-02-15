#include "level.h"

#include <cmath>

namespace objects 
{
	Level::Level(iPoint size) : mSize(size)
	{
		matrix::fill(mLand, mSize, Tile(TileName::Wall));
	}

	void Level::draw(window::ptr &win, iPoint offset)
	{
		for(int i = 1; i < mLand.size(); ++i) {
			for (int j = 1; j < mLand[i].size(); ++j) {
				mLand[i][j].drawAt(win, iPoint(i - offset.x,j - offset.y));
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

	void Level::addRoom(iPoint p)
	{
		mRooms.push_back(p);
	}

	const std::vector<iPoint> &Level::rooms() const
	{
		return mRooms;
	}

	const Matrix<Tile> &Level::land() const
	{
		return mLand;
	}
}