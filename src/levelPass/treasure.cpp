#include "treasure.h"

#include <random>

namespace levelPass
{
	Treasure::Treasure(int count, int mLevel) : mCount(count)
	{

	}

	void Treasure::execute(objects::Level &l)
	{
		for (int i = 0; i < mCount; ++i) {
			spawnTreasure(l);
		}
	}

	void Treasure::spawnTreasure(objects::Level &l)
	{
		while (true) {
			auto size = l.size();

			std::random_device rd;
			std::mt19937 mt(rd());

			std::uniform_int_distribution<int> maxX(2, size.x - 2);
			std::uniform_int_distribution<int> maxY(2, size.y - 2);

			int x = maxX(mt);
			int y = maxY(mt);

			for (int i = x; i < size.x; i++) {
				for (int j = y; j < size.y; j++) {
					if (l.get(iPoint(i,j)).name() == objects::TileName::Empty) {
						l.set(iPoint(i, j), objects::Tile(objects::TileName::Treasure));
						return;
					}
				}
			}
		}
	}
}