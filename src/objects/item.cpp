#include "item.h"

#include <random>

namespace objects
{
	Item::Item(std::string name, bool weapon, bool armor, int strength, int constitution, int dexterity, int agility, int magicka) :
	Attribute(strength, constitution, dexterity, agility, magicka), name(name), weapon(weapon), armor(armor)
	{}

	namespace items
	{
		Item loot(int level)
		{
			std::random_device rd;
			std::mt19937 mt(rd());

			if (level > 10) {
				std::uniform_int_distribution<int> loot(0, 1);
				switch (loot(mt)) {
				case 0:
					return swordMystic();
				case 1:
					return swordSteel();
				}
			}
			if (level > 5) {
				return swordBronze();
			}
			return swordWood();
		}

		Item swordWood()
		{
			return Item{
				"wooden sword",
				true, false,
				3, 1, 1, 1, 0
			};
		}

		Item swordBronze()
		{
			return Item{
				"bronze sword",
				true, false,
				5, 1, 2, 1, 0
			};
		}

		Item swordSteel()
		{
			return Item{
				"bronze sword",
				true, false,
				8, 1, 3, 0, 0
			};
		}

		Item swordMystic()
		{
			return Item{
				"bronze sword",
				true, false,
				1, 1, 3, 0, 8
			};
		}
	}
}