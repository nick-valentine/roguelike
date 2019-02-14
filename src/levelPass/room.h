#ifndef LEVELPASS_ROOM_H
#define LEVELPASS_ROOM_H

#include "abstract.h"
#include "../objects/level.h"

namespace levelPass
{
	class Room : public Abstract
	{
	public:
		virtual ~Room() = default;

		virtual void execute(objects::Level &l);
	};
}

#endif // LEVELPASS_ROOM_H