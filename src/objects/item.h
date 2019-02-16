#ifndef OBEJCTS_ITEM_H
#define OBEJCTS_ITEM_H

#include <string>

#include "attribute.h"

namespace objects
{
	class EntityAttribute;
	class Item;
	typedef bool(*UseFunc)(Item *i, EntityAttribute *e);

	class Item : public Attribute
	{
	public:
		Item(std::string name, bool weapon, bool armor, bool useable, int strength, int constitution, int dexterity, int agility, int magicka);

		bool use(EntityAttribute *e);

		std::string name;
		bool weapon = false;
		bool armor = false;
		bool useable = false;
		UseFunc mUse = nullptr;
		uint memory = 0;
	};

	namespace items
	{
		Item loot(int level);
		// swords
		Item swordWood();
		Item swordBronze();
		Item swordSteel();
		Item swordMystic();

		// wands
		Item wandBasic();
		Item wandMajestic();

		// daggers
		Item daggerWood();
		Item daggerBronze();
		Item daggerSteel();
		Item daggerMystic();

		// misc
		Item picaxe();
		Item club();
		Item bucket();

		// armors
		Item helmetWood();
		Item tunicCloth();
		Item tunicLeather();
		Item tunicIron();

		// potions
		Item smallHealthPotion();
		Item mediumHealthPotion();
		Item bigHealthPotion();
		Item potionBlue();
		Item potionGreen();
		Item potionYellow();
		Item potionBlack();
		Item potionPurple();

		// misc
		Item bite();
	}
}

#endif // OBJECTS_ITEM_H