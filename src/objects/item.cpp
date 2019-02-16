#include "item.h"
#include "entityAttribute.h"
#include "itemFuncs.h"

#include <random>

namespace objects
{
	Item::Item(std::string name, bool weapon, bool armor, bool useable, int strength, int constitution, int dexterity, int agility, int magicka) :
	Attribute(strength, constitution, dexterity, agility, magicka), name(name), weapon(weapon), armor(armor), useable(useable)
	{}

	bool Item::use(EntityAttribute *e)
	{
		mUse(this, e);
	}

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
			std::uniform_int_distribution<int> loot(0, 1);
			switch (loot(mt)) {
			case 0:
				return swordWood();
			case 1:
				return helmetWood();
			}
			
		}

		Item swordWood()
		{
			return Item{
				"wooden sword",
				true, false, false,
				3, 1, 1, 1, 0
			};
		}

		Item swordBronze()
		{
			return Item{
				"bronze sword",
				true, false, false,
				5, 1, 2, 1, 0
			};
		}

		Item swordSteel()
		{
			return Item{
				"bronze sword",
				true, false, false,
				8, 1, 3, 0, 0
			};
		}

		Item swordMystic()
		{
			return Item{
				"bronze sword",
				true, false, false,
				1, 1, 3, 0, 8
			};
		}

		Item helmetWood()
		{
			return Item{
				"wooden helmet",
				false, true, false,
				1, 3, 1, 0, 0
			};
		}

		Item smallHealthPotion()
		{
			Item i{
				"health potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::heal<5>;
			return i;
		}


	}
}