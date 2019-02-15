#include "entity.h"
#include "entityBrain.h"
#include "level.h"

namespace objects
{
	Entity::Entity(iPoint pos, char rep, int color, std::string name, UpdateFunc func) : mPos(pos), mRep(rep), mColor(color), name(name), mFunc(func)
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

	void Entity::update(const Level &l, Context *ctx)
	{
		mFunc(this, ctx, l);
	}

	Entity makePlayer(iPoint pos)
	{
		return Entity{
			pos,
			'A',
			2,
			"player",
			brain::player
		};
	}

	Entity makeGrunt(iPoint pos)
	{
		return Entity{
			pos,
			'G',
			3,
			"grunt",
			brain::randMover
		};
	}
}