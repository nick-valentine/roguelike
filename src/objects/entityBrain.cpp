#include "entityBrain.h"
#include "entity.h"

namespace objects::brain {
	void player(objects::Entity *e, Context *ctx)
	{
		switch (ctx->input) {
		case Input::UP:
			e->move(iPoint(0, -1));
			break;
		case Input::DOWN:
			e->move(iPoint(0, 1));
			break;
		case Input::LEFT:
			e->move(iPoint(-1, 0));
			break;
		case Input::RIGHT:
			e->move(iPoint(1, 0));
			break;
		}
	}
}