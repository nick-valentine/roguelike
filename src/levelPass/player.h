#ifndef LEVELPASS_PLAYER_H
#define LEVELPASS_PLAYER_H

#include "abstract.h"

namespace levelPass
{
	class Player : public Abstract
	{
	public:
		virtual ~Player() = default;

		virtual void execute(objects::Level &l);
	private:
	};
}

#endif // LEVELPASS_PLAYER_H