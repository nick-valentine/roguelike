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

		for (const auto &i : mEntities) {
			i.drawAt(win, offset);
		}
	}

	void Level::update(Context *ctx)
	{
		for (auto &i : mEntities) {
			i.update(*this, ctx);
		}
	}

	iPoint Level::size()
	{
		return mSize;
	}

	Tile Level::get(iPoint at) const
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

	void Level::addEntity(Entity e)
	{
		mEntities.push_back(e);
	}

	void Level::setPlayer(Entity e)
	{
		mPlayer = mEntities.size();
		mEntities.push_back(e);
	}

	const Entity *Level::getPlayer() const
	{
		return &mEntities[mPlayer];
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