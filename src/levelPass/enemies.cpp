#include "enemies.h"

#include <random>

namespace levelPass
{
	Enemies::Enemies(int count) : mCount(count)
	{

	}

	void Enemies::execute(objects::Level &l)
	{
		for (int i = 0; i < mCount; ++i) {
			spawnEnemy(l);
		}
	}

	void Enemies::spawnEnemy(objects::Level &l)
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
						l.addEntity(spawn(iPoint(i,j)));
						return;
					}
				}
			}
		}
	}

	objects::Entity Enemies::spawn(iPoint where)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> which(0, 13);
		switch (which(mt)) {
		case 0:
			return objects::makeGrunt(where);
		case 1:
			return objects::makeSpiderGrunt(where);
		case 2:
			return objects::makeSpiderWorker(where);
		case 3:
			return objects::makeSpiderQueen(where);
		case 4:
			return objects::makeSpiderSoldier(where);
		case 5:
			return objects::makeGoblinGrunt(where);
		case 6:
			return objects::makeGoblinWorker(where);
		case 7:
			return objects::makeHobgoblin(where);
		case 8:
			return objects::makeOrcSoldier(where);
		case 9:
			return objects::makeOrcScout(where);
		case 10:
			return objects::makeSkeletonWonderer(where);
		case 11:
			return objects::makeZombie(where);
		case 12:
			return objects::makeZombieJuggernaut(where);
		}
	}
}