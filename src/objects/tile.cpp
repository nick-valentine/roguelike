#include "tile.h"

namespace objects
{
	const std::array<TileType, 2> Tile::Tiles = {
		TileType('#', 1, true),
		TileType(' ', 1, false)
	};

	Tile::Tile(TileName type) : mType((int)type)
	{
	}

	void Tile::drawAt(window::ptr &win, iPoint pos)
	{
		win->put(
			Tile::Tiles[mType].colorPair,
			/* layer */ 1,
			Tile::Tiles[mType].tile,
			pos
		);
	}

	TileType Tile::getType(uint i)
	{
		return Tile::Tiles[i];
	}
}

