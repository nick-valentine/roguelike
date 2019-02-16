#ifndef OBEJCTS_ITEM_H
#define OBEJCTS_ITEM_H

#include <string>

#include "attribute.h"

namespace objects
{
	class Item : public Attribute
	{
	public:
		Item(std::string name, bool weapon, bool armor, int strength, int constitution, int dexterity, int agility, int magicka);

		std::string name;
		bool weapon = false;
		bool armor = false;
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
	}
}

#endif // OBJECTS_ITEM_H