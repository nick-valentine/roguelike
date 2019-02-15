#ifndef OBJECTS_LEVEL_H
#define OBJECTS_LEVEL_H

#include <vector>
#include <memory>
#include <algorithm>

#include "../utility/point.h"
#include "../utility/matrix.h"
#include "../window/abstract.h"

#include "tile.h"

using namespace utility;

namespace objects 
{
	class Level
	{
	public:
		Level(iPoint size);

		void draw(window::ptr &win, iPoint offset);

		iPoint size();
		Tile get(iPoint at);
		void set(iPoint at, Tile t);
		void addRoom(iPoint p);
		const std::vector<iPoint> &rooms() const;

		const Matrix<Tile> &land() const;
	private:
		iPoint mSize;
		Matrix<Tile> mLand;
		std::vector<iPoint> mRooms;
	};
}
#endif // OBJECTS_LEVEL_H