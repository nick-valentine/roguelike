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
				health+=5;
				maxHealth+=5;
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

	void EntityAttribute::award(Item i)
	{
		if (i.weapon) {
			weapons.push_back(i);
			return;
		}
		inventory.push_back(i);
	}

	void EntityAttribute::equip(uint i)
	{
		if (inventory[i].armor) {
			armor.push_back(inventory[i]);
			inventory[i] = inventory[inventory.size() - 1];
			inventory.pop_back();
		}
	}

	void EntityAttribute::dequip(uint i)
	{
		inventory.push_back(armor[i]);
		armor[i] = armor[armor.size() - 1];
		armor.pop_back();
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
			e.armor.push_back(objects::items::helmetWood());
			e.inventory.push_back(objects::items::smallHealthPotion());
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

		EntityAttribute worker(uint level)
		{
			EntityAttribute e{
				15,
				5,
				5,
				2,
				3,
				0
			};

			e.weapons.push_back(objects::items::picaxe());
			e.levelUp(level - 1);
			return e;
		}

		EntityAttribute soldier(uint level)
		{
			EntityAttribute e{
				20,
				7,
				7,
				4,
				4,
				0
			};

			e.armor.push_back(objects::items::tunicLeather());
			e.weapons.push_back(objects::items::swordBronze());
			e.levelUp(level - 1);
			return e;
		}

		EntityAttribute queen(uint level)
		{
			EntityAttribute e{
				15,
				7,
				7,
				6,
				4,
				8
			};

			e.armor.push_back(objects::items::tunicIron());
			e.weapons.push_back(objects::items::swordMystic());
			e.levelUp(level - 1);
			return e;
		}
	}
}