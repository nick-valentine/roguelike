#ifndef OBJECTS_ENTITY_H
#define OBJECTS_ENTITY_H

#include "../utility/point.h"
#include "../window/abstract.h"
#include "../context.h"

using namespace utility;

namespace objects
{
	class Entity;
	class Level;
	class EntityAttribute;

	typedef void(*UpdateFunc)(Entity*, Context*, const Level&);
	typedef EntityAttribute(*AttrFunc)(uint level);

	class Entity
	{
	public:
		Entity(iPoint pos, char rep, int color, std::string name, UpdateFunc func, AttrFunc aFunc);

		void move(iPoint by);
		iPoint pos() const;

		void drawAt(window::ptr &win, iPoint pos) const;
		void update(const Level &l, Context *ctx);
		EntityAttribute genAttributes(uint level) const;

		uint memory = 0;
		std::string name;
	private:
		iPoint mPos = {0,0};
		char mRep = ' ';
		int mColor = 0;
		UpdateFunc mFunc;
		AttrFunc mAFunc;
	};

	Entity makePlayer(iPoint pos);
	Entity makeGrunt(iPoint pos);
}

#endif // OBJECTS_ENTITY_H