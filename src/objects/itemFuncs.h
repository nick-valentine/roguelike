#ifndef OBJECTS_ITEMFUNCS_H
#define OBJECTS_ITEMFUNCS_H

#include "entityAttribute.h"

namespace objects {
	template <int N>
	bool heal(Item *i, EntityAttribute *e)
	{
		e->health += N;
		if (e->health > e->maxHealth) {
			e->health = e->maxHealth;
		}
		i->memory--;
		return i->memory <= 0;
	}
}

#endif //OBJECTS_ITEMFUNCS_H