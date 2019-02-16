#include "item.h"
#include "entityAttribute.h"
#include "itemFuncs.h"

#include <random>
#include <array>

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
			std::array<std::pair<Item(*)(), int>, 9> v{
				std::pair{swordWood, 10},
				std::pair{swordBronze, 5},
				std::pair{swordSteel, 3},
				std::pair{swordMystic, 1},
				std::pair{picaxe, 10},
				std::pair{helmetWood, 10},
				std::pair{tunicLeather, 5},
				std::pair{tunicIron, 3},
				std::pair{smallHealthPotion, 5}
			};
			int total = 0;
			for (const auto &i : v) {
				total += i.second;
			}

			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_int_distribution<int> loot(0, total);

			for (const auto &i : v) {
				total -= i.second;
				if (total <= 0) {
					return i.first();
				}
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
				"mystic sword",
				true, false, false,
				1, 1, 3, 0, 8
			};
		}

		Item picaxe()
		{
			return Item{
				"picaxe",
				true, false, false,
				4, 1, 2, 1, 0
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

		Item tunicLeather()
		{
			return Item{
				"leather tunic",
				false, true, false,
				1, 5, 1, 0, 0
			};
		}

		Item tunicIron()
		{
			return Item{
				"iron tunic",
				false, true, false,
				1, 8, 1, 0, 0
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