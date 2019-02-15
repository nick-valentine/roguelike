#include "entityAttribute.h"

#include <random>

namespace objects
{
	EntityAttribute::EntityAttribute(int health, int strength, int constitution, int dexterity, int agility, int magicka) :
		health(health), maxHealth(health), strength(strength), constitution(constitution), dexterity(dexterity), agility(agility), magicka(magicka)
	{}

	void EntityAttribute::levelUp(uint count)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> dist(0, 3);
		for (int i = 0; i < count; ++i) {
			level++;
			auto which = dist(mt);
			switch (which) {
			case 0:
				health++;
				break;
			case 1:
				strength++;
				break;
			case 2:
				dexterity++;
				break;
			}
		}
	}

	namespace attributes {
		EntityAttribute basePlayer(uint level)
		{
			return EntityAttribute{
				20,
				5,
				5,
				5,
				5,
				5
			};
		}

		EntityAttribute grunt(uint level)
		{
			EntityAttribute e{
				10,
				2,
				2,
				2,
				3,
				0
			};

			e.levelUp(level - 1);
			return e;
		}
	}
}