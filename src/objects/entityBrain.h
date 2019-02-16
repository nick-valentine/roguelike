#ifndef OBJECTS_ENTITY_BRAIN_H
#define OBJECTS_ENTITY_BRAIN_H

#include "../context.h"
#include "../utility/point.h"

using namespace utility;

namespace objects {
	class Entity;
	class Level;
}

namespace objects::brain {
	namespace helper {
		bool canMove(iPoint to, const objects::Level &l);
	}
	void player(objects::Entity *e, Context *ctx, const objects::Level &l);
	void randMover(objects::Entity *e, Context *ctx, const objects::Level &l);
	void blindSniffer(objects::Entity *e, Context *ctx, const objects::Level &l);
}

#endif // OBJECTS_ENTITY_BRAIN_H