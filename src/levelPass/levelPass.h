#ifndef LEVELPASS_H
#define LEVELPASS_H

#include "abstract.h"
#include "room.h"

namespace levelPass
{
	using ptr = std::unique_ptr<Abstract>;

	std::vector<ptr> defaultPasses();
}
#endif // LEVELPASS_H