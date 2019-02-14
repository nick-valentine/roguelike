#include "hallway.h"

#include "../utility/route.h"

#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <functional>

namespace levelPass
{
	void Hallway::execute(objects::Level &l)
	{
		auto m = l.land();
		if (m.size() == 0) {
			return;
		}
		mSize = {(int)m.size(), (int)m[0].size()};

		std::vector< std::future<
			std::vector<iPoint>
		> > futures;

		std::vector<std::thread> threads;

		for (int i = 0; i < l.rooms().size() - 1; ++i) {
			std::packaged_task<
				std::vector<iPoint>(objects::Level, const Matrix<objects::Tile>*, uint)
			> task(std::bind(&Hallway::lerp, this, std::ref(l), &m, i));

			futures.push_back(task.get_future());

			threads.push_back(std::thread(std::move(task), std::ref(l), &m, i));
		}

		std::for_each(threads.begin(), threads.end(), [](std::thread &t) {t.join();});

		for (auto &result : futures) {
			for (const auto &k : result.get()) {
				open(l, k);
			}
		}
	}

	std::vector<iPoint> Hallway::findNextPath(objects::Level &l, const Matrix<objects::Tile> *m, uint roomIDX)
	{
		auto rooms = l.rooms();
		if (roomIDX >= rooms.size()-1) {
			return std::vector<iPoint>();
		}
		auto current = rooms[roomIDX];
		auto next = rooms[roomIDX+1];

		Route<objects::Tile> r(*m);
		return r.find(current, next, [](objects::Tile t)->bool{return t.describe().collidable;});
	}

	std::vector<iPoint> Hallway::lerp(objects::Level &l, const Matrix<objects::Tile> *m, uint roomIDX)
	{
		std::vector<iPoint> v;
		auto rooms = l.rooms();
		if (roomIDX >= rooms.size()-1) {
			return std::vector<iPoint>();
		}
		auto current = rooms[roomIDX];
		auto next = rooms[roomIDX+1];

		iPoint sign{1,1};
		if (current.x > next.x) {
			sign.x = -1;
		}
		if (current.y > next.y) {
			sign.y = -1;
		}

		while (current != next) {
			std::cout<<"("<<current.x<<","<<current.y<<")\n";
			v.push_back(current);
			if (current.x != next.x) {
				current.x += sign.x;
				continue;
			}
			if (current.y != next.y) {
				current.y += sign.y;
				continue;
			}
		}
		return v;
	}

	void Hallway::open(objects::Level &l, iPoint k)
	{
		l.set(k, objects::Tile(objects::TileName::Empty));
		l.set(iPoint{k.x-1,k.y}, objects::Tile(objects::TileName::Empty));
		l.set(iPoint{k.x-1,k.y-1}, objects::Tile(objects::TileName::Empty));
		l.set(iPoint{k.x,k.y-1}, objects::Tile(objects::TileName::Empty));
	}
}