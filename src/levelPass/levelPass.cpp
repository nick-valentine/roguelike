#include "levelPass.h"

namespace levelPass
{
	std::vector<ptr> defaultPasses()
	{
		std::vector<ptr> p;
		p.push_back(std::make_unique<Room>(10));
		p.push_back(std::make_unique<Hallway>());
		return p;
	}
}