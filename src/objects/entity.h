#ifndef OBJECTS_ENTITY_H
#define OBJECTS_ENTITY_H

#include "../utility/point.h"
#include "../window/abstract.h"
#include "../context.h"

using namespace utility;

namespace objects
{
	class Entity;

	typedef void(*UpdateFunc)(Entity*, Context*);

	class Entity
	{
	public:
		Entity(iPoint pos, char rep, int color, UpdateFunc func);

		void move(iPoint by);
		iPoint pos() const;

		void drawAt(window::ptr &win, iPoint pos) const;
		void update(Context *ctx);
	private:
		iPoint mPos = {0,0};
		char mRep = ' ';
		int mColor = 0;
		UpdateFunc mFunc;
	};

	Entity makePlayer(iPoint pos);
}

#endif // OBJECTS_ENTITY_H