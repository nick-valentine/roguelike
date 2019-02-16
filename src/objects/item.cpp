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
			std::array<std::pair<Item(*)(), int>, 19> v{
				std::pair{swordWood, 10},
				std::pair{swordBronze, 5},
				std::pair{swordSteel, 3},
				std::pair{swordMystic, 1},
				std::pair{daggerWood, 10},
				std::pair{daggerBronze, 5},
				std::pair{daggerSteel, 3},
				std::pair{daggerMystic, 1},
				std::pair{wandBasic, 2},
				std::pair{wandMajestic, 1},
				std::pair{club, 15},
				std::pair{picaxe, 10},
				std::pair{helmetWood, 10},
				std::pair{tunicCloth, 8},
				std::pair{tunicLeather, 5},
				std::pair{tunicIron, 3},
				std::pair{smallHealthPotion, 5},
				std::pair{mediumHealthPotion, 3},
				std::pair{mediumHealthPotion, 1}
			};
			int total = 0;
			for (const auto &i : v) {
				total += i.second;
			}

			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_int_distribution<int> loot(0, total);

			auto r = loot(mt);
			for (const auto &i : v) {
				r -= i.second;
				if (r <= 0) {
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


		Item daggerWood()
		{
			return Item{
				"wooden dagger",
				true, false, false,
				2, 1, 2, 1, 0
			};
		}

		Item daggerBronze()
		{
			return Item{
				"bronze dagger",
				true, false, false,
				4, 1, 4, 1, 0
			};
		}

		Item daggerSteel()
		{
			return Item{
				"bronze dagger",
				true, false, false,
				7, 1, 6, 0, 0
			};
		}

		Item daggerMystic()
		{
			return Item{
				"mystic dagger",
				true, false, false,
				0, 1, 7, 0, 7
			};
		}

		Item wandBasic()
		{
			return Item{
				"basic wand",
				true, false, false,
				0, 1, 3, 0, 3
			};
		}

		Item wandMajestic()
		{
			return Item{
				"majestic wand",
				true, false, false,
				0, 1, 3, 0, 8
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

		Item club()
		{
			return Item{
				"club",
				true, false, false,
				2, 1, 2, 1, 0
			};
		}

		Item bucket()
		{
			return Item{
				"bucket",
				false, true, false,
				1, 4, 1, 0, 0
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

		Item tunicCloth()
		{
			return Item{
				"cloth tunic",
				false, true, false,
				1, 1, 6, 6, 6
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
				"small health potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::heal<5>;
			return i;
		}

		Item mediumHealthPotion()
		{
			Item i{
				"medium health potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 4;
			i.mUse = objects::heal<5>;
			return i;
		}

		Item bigHealthPotion()
		{
			Item i{
				"big health potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 6;
			i.mUse = objects::heal<5>;
			return i;
		}

		Item potionBlue()
		{
			Item i{
				"blue potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::coloredPotion<0>;
			return i;
		}

		Item potionGreen()
		{
			Item i{
				"green potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::coloredPotion<1>;
			return i;
		}

		Item potionYellow()
		{
			Item i{
				"yellow potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::coloredPotion<2>;
			return i;
		}

		Item potionBlack()
		{
			Item i{
				"black potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::coloredPotion<3>;
			return i;
		}

		Item potionPurple()
		{
			Item i{
				"purple potion",
				false, false, true,
				0, 0, 0, 0, 0
			};
			i.memory = 2;
			i.mUse = objects::coloredPotion<4>;
			return i;
		}

		Item bite()
		{
			return Item{
				"bite",
				false, false, true,
				4, 1, 4, 1, 4
			};
		}
	}
}