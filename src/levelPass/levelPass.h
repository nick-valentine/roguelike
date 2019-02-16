#ifndef LEVELPASS_H
#define LEVELPASS_H

#include "abstract.h"
#include "room.h"
#include "hallway.h"
#include "player.h"
#include "enemies.h"
#include "exit.h"
#include "treasure.h"

namespace levelPass
{
	using ptr = std::unique_ptr<Abstract>;

	std::vector<ptr> defaultPasses(int level);
}
#endif // LEVELPASS_H