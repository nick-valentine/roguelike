#include "entityAttribute.h"

#include <random>

namespace objects
{
	EntityAttribute::EntityAttribute(int health, int strength, int constitution, int dexterity, int agility, int magicka) :
		Attribute(strength, constitution, dexterity, agility, magicka), health(health), maxHealth(health)
	{}

	void EntityAttribute::levelUp(uint count)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> dist(0, 6);
		for (int i = 0; i < count; ++i) {
			level++;
			auto which = dist(mt);
			switch (which) {
			case 0:
				health++;
				maxHealth++;
				break;
			case 1:
				strength++;
				break;
			case 2:
				constitution++;
				break;
			case 3:
				dexterity++;
				break;
			case 4:
				agility++;
				break;
			case 6:
				magicka++;
				break;
			}
		}
	}

	namespace attributes {
		EntityAttribute basePlayer(uint level)
		{
			EntityAttribute e{
				20,
				5,
				5,
				5,
				5,
				5
			};
			e.weapons.push_back(objects::items::swordWood());
			return e;
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

			e.weapons.push_back(objects::items::swordWood());
			e.levelUp(level - 1);
			return e;
		}
	}
}