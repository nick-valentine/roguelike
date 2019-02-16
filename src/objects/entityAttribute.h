#ifndef OBJECTS_ENTITY_ATTRIBUTE_H
#define OBJECTS_ENTITY_ATTRIBUTE_H

#include <vector>

#include "attribute.h"
#include "item.h"

namespace objects
{
	class EntityAttribute : public Attribute
	{
	public:
		EntityAttribute() = default;
		EntityAttribute(int health, int strength, int constitution, int dexterity, int agility, int magicka);
		void award(Item i);
		void equip(uint i);
		void dequip(uint i);
		void levelUp(uint count);
		int level = 1;
		int health = 0;
		int maxHealth = 0;
		uint exp = 0;
		std::vector<Item> inventory;
		std::vector<Item> weapons;
		std::vector<Item> armor;
	};

	namespace attributes
	{
		EntityAttribute basePlayer(uint level);
		EntityAttribute grunt(uint level);
	}
}

#endif // OBJECTS_ENTITY_ATTRIBUTE_H