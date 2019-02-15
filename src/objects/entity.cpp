#include "entity.h"
#include "entityBrain.h"

namespace objects
{
	Entity::Entity(iPoint pos, char rep, int color, UpdateFunc func) : mPos(pos), mRep(rep), mColor(color), mFunc(func)
	{
	}

	void Entity::move(iPoint by)
	{
		mPos.x += by.x;
		mPos.y += by.y;
	}

	iPoint Entity::pos() const
	{
		return mPos;
	}

	void Entity::drawAt(window::ptr &win, iPoint pos) const
	{
		win->put(
			mColor,
			/* layer */ 99,
			mRep,
			iPoint(mPos.x - pos.x, mPos.y - pos.y)
		);
	}

	void Entity::update(Context *ctx)
	{
		mFunc(this, ctx);
	}

	Entity make_player(iPoint pos)
	{
		return Entity{
			pos,
			'A',
			2,
			brain::player
		};
	}
}