#include "entityAttribute.h"

namespace objects
{
	EntityAttribute::EntityAttribute(int health, int strength, int dexterity) :
		health(health), strength(strength), dexterity(dexterity)
	{}

	namespace attributes {
		EntityAttribute basePlayer()
		{
			return EntityAttribute{
				20,
				5,
				5
			};
		}
	}
}