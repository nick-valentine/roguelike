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

		// armors
		Item helmetWood();

		//potions
		Item smallHealthPotion();
	}
}

#endif // OBJECTS_ITEM_H