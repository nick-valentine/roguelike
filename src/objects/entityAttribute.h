#ifndef OBJECTS_ENTITY_ATTRIBUTE_H
#define OBJECTS_ENTITY_ATTRIBUTE_H

namespace objects
{
	class EntityAttribute
	{
	public:
		EntityAttribute() = default;
		EntityAttribute(int health, int strength, int dexterity);
		int health = 0;
		int strength = 0;
		int dexterity = 0;
	};

	namespace attributes
	{
		EntityAttribute basePlayer();
	}
}

#endif // OBJECTS_ENTITY_ATTRIBUTE_H