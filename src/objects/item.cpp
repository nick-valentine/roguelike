#include "item.h"

namespace objects
{
	Item::Item(std::string name, bool weapon, bool armor, int strength, int constitution, int dexterity, int agility, int magicka) :
	Attribute(strength, constitution, dexterity, agility, magicka), name(name), weapon(weapon), armor(armor)
	{}

	namespace items
	{
		Item swordWood()
		{
			return Item{
				"wooden sword",
				true, false,
				3, 1, 1, 1, 0
			};
		}
	}
}