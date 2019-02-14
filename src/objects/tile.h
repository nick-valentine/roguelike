#ifndef OBJECTS_TILE_H
#define OBJECTS_TILE_H

#include "../window/abstract.h"
#include "../utility/point.h"
#include "../utility/colorPallette.h"

using namespace utility;

namespace objects
{
	struct TileType {
		char tile;
		uint colorPair;
		bool collidable;

		TileType(
			char tile, uint colorPair, bool collidable
		) : tile(tile), colorPair(colorPair), collidable(collidable)
		{}
	};

	enum class TileName
	{
		Wall = 0,
		Empty,
		Count
	};

	class Tile
	{
	public:
		Tile(TileName type);

		void drawAt(window::ptr &win, iPoint pos);
		
		static TileType getType(uint i);
	private:
		static const std::array<TileType, 2> Tiles;

		int mType = 0;
	};
}
#endif // OBJECTS_TILE_H