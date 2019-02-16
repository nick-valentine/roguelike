#ifndef OBJECTS_ATTRIBUTE_H
#define OBJECTS_ATTRIBUTE_H

using uint = unsigned int;

namespace objects
{
	class Attribute
	{
	public:
		Attribute() = default;
		Attribute(int strength, int constitution, int dexterity, int agility, int magicka);
		int strength = 0;
		int constitution = 0;
		int dexterity = 0;
		int agility = 0;
		int magicka = 0;
	};
}
	

#endif // OBJECTS_ATTRIBUTE_H