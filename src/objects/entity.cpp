#include "entity.h"
#include "entityBrain.h"
#include "entityAttribute.h"
#include "level.h"

namespace objects
{
	Entity::Entity(iPoint pos, char rep, int color, std::string name, UpdateFunc func, AttrFunc aFunc) : 
		mPos(pos), mRep(rep), mColor(color), name(name), mFunc(func), mAFunc(aFunc)
	{
	}

	void Entity::move(iPoint by)
	{
		mPos.x += by.x;
		mPos.y += by.y;
	}

	void Entity::moveTo(iPoint to)
	{
		mPos = to;
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

	EntityAttribute Entity::genAttributes(uint level) const
	{
		return mAFunc(level);
	}

	Entity makePlayer(iPoint pos)
	{
		return Entity{
			pos,
			'A',
			2,
			"player",
			brain::player,
			attributes::basePlayer
		};
	}

	Entity makeGrunt(iPoint pos)
	{
		return Entity{
			pos,
			'G',
			3,
			"grunt",
			brain::randMover,
			attributes::grunt
		};
	}
}