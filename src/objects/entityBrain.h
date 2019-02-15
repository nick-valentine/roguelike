#ifndef OBJECTS_ENTITY_BRAIN_H
#define OBJECTS_ENTITY_BRAIN_H

#include "../context.h"

namespace objects {
	class Entity;
}

namespace objects::brain {
	void player(objects::Entity *e, Context *ctx);
}

#endif // OBJECTS_ENTITY_BRAIN_H