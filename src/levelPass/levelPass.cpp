#include "levelPass.h"

namespace levelPass
{
	std::vector<ptr> defaultPasses(int level)
	{
		std::vector<ptr> p;
		p.push_back(std::make_unique<Room>(40));
		p.push_back(std::make_unique<Hallway>());
		p.push_back(std::make_unique<Player>());
		p.push_back(std::make_unique<Enemies>(5 * level));
		p.push_back(std::make_unique<Exit>());
		return p;
	}
}
