#include "tile.h"

namespace objects
{
	const std::array<TileType, (int)TileName::Count> Tile::Tiles = {
		TileType('#', 1, true),
		TileType(' ', 1, false),
		TileType('D', 2, false),
		TileType('U', 2, false)
	};

	Tile::Tile(TileName type) : mType((int)type)
	{
	}

	void Tile::drawAt(window::ptr &win, iPoint pos, bool cull)
	{
		if (!cull) {
			mHasBeenSeen = true;
			win->put(
				Tile::Tiles[mType].colorPair,
				/* layer */ 1,
				Tile::Tiles[mType].tile,
				pos
			);
		} else if (mHasBeenSeen) {
			win->put(
				0,
				/* layer */ 1,
				Tile::Tiles[mType].tile,
				pos
			);
		}
	}

	const TileType Tile::describe() const
	{
		return Tile::Tiles[mType];
	}

	TileName Tile::name() const
	{
		return TileName(mType);
	}

	const TileType Tile::getType(uint i)
	{
		return Tile::Tiles[i];
	}
}

