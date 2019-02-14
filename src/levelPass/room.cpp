#include "room.h"

#include <random>

namespace levelPass
{
	Room::Room(int count) : mCount(count)
	{
	}

	void Room::execute(objects::Level &l)
	{
		auto size = l.size();

		for (int i = 0; i < mCount; ++i) {
			auto rect = this->genBoundries(size);
			this->clearRoom(l, rect);
		}
	}

	iRectangle Room::genBoundries(iPoint size)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> startDistX(2, size.x - 2);
		std::uniform_int_distribution<int> startDistY(2, size.y - 2);
		std::uniform_int_distribution<int> sizeDistX(minRoomSizeX, maxRoomSizeX);
		std::uniform_int_distribution<int> sizeDistY(minRoomSizeY, maxRoomSizeY);

		int x = startDistX(mt);
		int y = startDistY(mt);
		int w = sizeDistX(mt);
		int h = sizeDistY(mt);
		if (x + w >= size.x - 2) {
			w = (size.x - x) - 2;
		}
		if (y + h >= size.y - 2) {
			h = (size.y - y) - 2;
		}
		return iRectangle(x, y, w, h);
	}

	void Room::clearRoom(objects::Level &l, iRectangle &rec)
	{
		for (int i = 0; i < rec.w; ++i) {
			for (int j = 0; j < rec.h; ++j) {
				l.set(iPoint(i + rec.x, j + rec.y), objects::Tile(objects::TileName::Empty));
			}
		}
	}
}