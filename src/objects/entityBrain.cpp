#include "entityBrain.h"
#include "entity.h"
#include "level.h"

namespace objects::brain {
	namespace helper
	{
		bool canMove(iPoint to, const objects::Level &l)
		{
			return !l.get(to).describe().collidable;
		}
	}

	void player(objects::Entity *e, Context *ctx, const Level &l)
	{
		iPoint delta{0,0};
		switch (ctx->input) {
		case Input::UP:
			delta = iPoint(0, -1);
			break;
		case Input::DOWN:
			delta = iPoint(0, 1);
			break;
		case Input::LEFT:
			delta = iPoint(-1, 0);
			break;
		case Input::RIGHT:
			delta = iPoint(1, 0);
			break;
		}

		auto pos = e->pos();
		iPoint to{pos.x + delta.x, pos.y + delta.y};
		if (helper::canMove(to, l)) {
			e->move(delta);
		}
	}
}