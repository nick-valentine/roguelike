#ifndef OBJECTS_LEVEL_H
#define OBJECTS_LEVEL_H

#include <vector>
#include <memory>
#include <algorithm>
#include <utility>

#include "../utility/point.h"
#include "../utility/matrix.h"
#include "../window/abstract.h"
#include "../context.h"

#include "tile.h"
#include "entity.h"

using namespace utility;

namespace objects 
{
	class Level
	{
	public:
		Level(iPoint size);

		void draw(window::ptr &win, iPoint offset);
		void update(Context *ctx);
		std::pair<int, int> checkCollision();

		iPoint size();
		Tile get(iPoint at) const;
		void set(iPoint at, Tile t);
		void addRoom(iPoint p);
		void addEntity(Entity e);
		const Entity *getEntity(int i) const;
		void bumpPlayer();
		void killEntity(int i);
		void setPlayer(Entity e);
		const Entity *getPlayer() const;
		const std::vector<iPoint> &rooms() const;

		const Matrix<Tile> &land() const;
	private:
		int mPlayer = -1;
		iPoint mSize;
		Matrix<Tile> mLand;
		std::vector<iPoint> mRooms;
		std::vector<Entity> mEntities;
	};
}
#endif // OBJECTS_LEVEL_H