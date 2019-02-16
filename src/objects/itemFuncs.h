#ifndef OBJECTS_ITEMFUNCS_H
#define OBJECTS_ITEMFUNCS_H

#include <map>
#include <vector>
#include <random>

#include "entityAttribute.h"

namespace objects 
{
	static std::map<int, bool(*)(Item *i, EntityAttribute *)> mapping;
	void createMapping();

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

	template <int N>
	bool coloredPotion(Item *i, EntityAttribute *e)
	{
		return mapping[N](i, e);
	}
}

#endif //OBJECTS_ITEMFUNCS_H