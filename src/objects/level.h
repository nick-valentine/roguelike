#ifndef OBJECTS_LEVEL_H
#define OBJECTS_LEVEL_H

#include <vector>
#include <memory>

#include "../utility/point.h"
#include "../window/abstract.h"

#include "tile.h"

using namespace utility;

namespace objects 
{
	class Level
	{
	public:
		Level(iPoint size);

		void draw(window::ptr &win);

		iPoint size();
		Tile get(iPoint at);
		void set(iPoint at, Tile t);
	private:
		iPoint mSize;
		std::vector< std::vector< Tile > > mLand;
	};
}
#endif // OBJECTS_LEVEL_H