#include "entityBrain.h"
#include "entity.h"
#include "level.h"

#include <random>

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

	void randMover(objects::Entity *e, Context *ctx, const Level &l)
	{
		std::random_device rd;
		std::mt19937 mt(rd());

		std::uniform_int_distribution<int> by(-1, 1);

		iPoint delta{0,0};
		if (by(mt) > 0) {
			delta.x = by(mt);
		} else {
			delta.y = by(mt);
		}

		auto pos = e->pos();
		iPoint to{pos.x + delta.x, pos.y + delta.y};
		if (helper::canMove(to, l)) {
			e->move(delta);
		}
	}
}