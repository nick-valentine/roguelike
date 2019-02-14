#include "levelPass.h"

namespace levelPass
{
	std::vector<ptr> defaultPasses()
	{
		std::vector<ptr> p;
		p.push_back(std::make_unique<Room>(30));
		return p;
	}
}