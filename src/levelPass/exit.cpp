#include "exit.h"

#include <random>
#include "../objects/entity.h"

namespace levelPass
{
	void Exit::execute(objects::Level &l)
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
					if (!l.get(iPoint(i,j)).describe().collidable) {
						l.set(iPoint(i,j), objects::Tile(objects::TileName::DownStairs));
						return;
					}
				}
			}
		}
	}
}