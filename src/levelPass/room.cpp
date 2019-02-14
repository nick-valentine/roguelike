#include "room.h"

namespace levelPass
{
	void Room::execute(objects::Level &l)
	{
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				l.set(iPoint(i + 10, j + 10), objects::Tile(objects::TileName::Empty));
			}
		}
	}
}