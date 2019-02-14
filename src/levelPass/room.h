#ifndef LEVELPASS_ROOM_H
#define LEVELPASS_ROOM_H

#include "abstract.h"

#include "../objects/level.h"
#include "../utility/rectangle.h"

using namespace utility;

namespace levelPass
{
	class Room : public Abstract
	{
	public:
		Room(int count);
		virtual ~Room() = default;

		virtual void execute(objects::Level &l);
	private:
		static constexpr int maxRoomSizeX = 20;
		static constexpr int maxRoomSizeY = 20;
		static constexpr int minRoomSizeX = 5;
		static constexpr int minRoomSizeY = 5;
		iRectangle genBoundries(iPoint size);
		void clearRoom(objects::Level &l, iRectangle &rec);

		int mCount = 0;
	};
}

#endif // LEVELPASS_ROOM_H