#ifndef LEVELPASS_HALLWAY_H
#define LEVELPASS_HALLWAY_H

#include "abstract.h"

#include "../utility/route.h"
#include "../utility/rectangle.h"

#include "../objects/level.h"
#include "../objects/tile.h"

namespace levelPass
{
	class Hallway : public Abstract
	{
	public:
		virtual ~Hallway() = default;

		virtual void execute(objects::Level &l);
	private:
		void makeNextReachable(objects::Level &l, const Matrix<objects::Tile> *m, uint roomIDX);
		void open(objects::Level &l, iPoint p);

		iPoint mSize;
	};
}

#endif // LEVELPASS_HALLWAY_H