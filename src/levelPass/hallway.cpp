#include "hallway.h"

#include "../utility/route.h"

#include <iostream>
#include <thread>
#include <vector>

namespace levelPass
{
	void Hallway::execute(objects::Level &l)
	{
		auto m = l.land();
		if (m.size() == 0) {
			return;
		}
		mSize = {(int)m.size(), (int)m[0].size()};

		std::vector<std::thread> threads;
		for (int i = 0; i < l.rooms().size() - 1; ++i) {
			threads.push_back(std::thread(&Hallway::makeNextReachable, this, std::ref(l), &m, i));
		}
		std::for_each(threads.begin(), threads.end(), [](std::thread &t) {t.join();});
	}

	void Hallway::makeNextReachable(objects::Level &l, const Matrix<objects::Tile> *m, uint roomIDX)
	{
		std::cerr<<roomIDX<<" started"<<std::endl;
		auto rooms = l.rooms();
		if (roomIDX >= rooms.size()-1) {
			return;
		}
		auto current = rooms[roomIDX];
		auto next = rooms[roomIDX+1];

		Route<objects::Tile> r(*m);
		auto path = r.find(current, next, [](objects::Tile t)->bool{return t.describe().collidable;});
		for (const auto &k : path) {
			open(l, k);
		}
		std::cerr<<roomIDX<<" done"<<std::endl;
	}

	void Hallway::open(objects::Level &l, iPoint k)
	{
		l.set(k, objects::Tile(objects::TileName::Empty));
		l.set(iPoint{k.x-1,k.y}, objects::Tile(objects::TileName::Empty));
		l.set(iPoint{k.x-1,k.y-1}, objects::Tile(objects::TileName::Empty));
		l.set(iPoint{k.x,k.y-1}, objects::Tile(objects::TileName::Empty));
	}
}