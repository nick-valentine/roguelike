#include "level.h"

#include <cmath>

#define MAX_VIEW_DISTANCE 7

namespace objects 
{
	Level::Level(iPoint size) : mSize(size)
	{
		matrix::fill(mLand, mSize, Tile(TileName::Wall));
	}

	void Level::draw(window::ptr &win, iPoint offset)
	{
		auto p = getPlayer()->pos();
		for(int i = 1; i < mLand.size(); ++i) {
			for (int j = 1; j < mLand[i].size(); ++j) {
				iPoint diff(p.x - i, p.y - j);
				int distance = sqrt((diff.y * diff.y)+(diff.x * diff.x));
				mLand[i][j].drawAt(win, iPoint(i - offset.x,j - offset.y), distance > MAX_VIEW_DISTANCE);
			}
		}

		for (const auto &i : mEntities) {
			auto e = i.pos();
			iPoint diff(p.x - e.x, p.y - e.y);
			int distance = sqrt((diff.y * diff.y)+(diff.x * diff.x));
			if (distance <= MAX_VIEW_DISTANCE) {
				i.drawAt(win, offset);
			}
		}
	}

	void Level::update(Context *ctx)
	{
		for (auto &i : mEntities) {
			i.update(*this, ctx);
		}
	}

	std::pair<int, int> Level::checkCollision()
	{
		for (int i = 0; i < mEntities.size(); ++i) {
			for (int j = i + 1; j < mEntities.size(); ++j) {
				if (mEntities[i].pos() == mEntities[j].pos()) {
					return std::pair{i,j};
				}
			}
		}
		return std::pair{-1, -1};
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

	void Level::killEntity(int i)
	{
		mEntities[i] = mEntities[mEntities.size() - 1];
		mEntities.pop_back();		
	}

	const Entity *Level::getEntity(int i) const
	{
		return &mEntities[i];
	}

	void Level::bumpPlayer(int distance)
	{
		auto pos = mEntities[mPlayer].pos();
		if (pos.x < distance + 1) {
			pos.x = distance + 1;
		}
		if (pos.x > (mSize.x - distance) - 1) {
			pos.x = (mSize.x - distance) - 1;
		}
		if (pos.y < distance + 1) {
			pos.y = distance + 1;
		}
		if (pos.y > (mSize.y - distance) - 1) {
			pos.y = (mSize.y - distance) - 1;
		}
		for (int i = pos.x - distance; i < pos.x + distance; ++i) {
			for (int j = pos.y - distance; j <  pos.y + distance; ++j) {
				if (!mLand[i][j].describe().collidable) {
					mEntities[mPlayer].moveTo(iPoint(i, j));
					return;
				}
			}
		}
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