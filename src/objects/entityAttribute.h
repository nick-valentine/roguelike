#ifndef OBJECTS_ENTITY_ATTRIBUTE_H
#define OBJECTS_ENTITY_ATTRIBUTE_H

using uint = unsigned int;

namespace objects
{
	class EntityAttribute
	{
	public:
		EntityAttribute() = default;
		EntityAttribute(int health, int strength, int constitution, int dexterity, int agility, int magicka);
		void levelUp(uint count);
		int level = 1;
		int health = 0;
		int maxHealth = 0;
		int strength = 0;
		int constitution = 0;
		int dexterity = 0;
		int agility = 0;
		int magicka = 0;
	};

	namespace attributes
	{
		EntityAttribute basePlayer(uint level);
		EntityAttribute grunt(uint level);
	}
}

#endif // OBJECTS_ENTITY_ATTRIBUTE_H