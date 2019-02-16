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
			"goblin grunt",
			brain::randMover,
			attributes::grunt
		};
	}

	Entity makeSpiderGrunt(iPoint pos)
	{
		return Entity{
			pos,
			'*',
			4,
			"spider grunt",
			brain::randMover,
			attributes::grunt
		};
	}

	Entity makeSpiderWorker(iPoint pos)
	{
		return Entity{
			pos,
			'*',
			4,
			"spider worker",
			brain::randMover,
			attributes::worker
		};
	}

	Entity makeSpiderQueen(iPoint pos)
	{
		return Entity{
			pos,
			'*',
			4,
			"spider queen",
			brain::blindSniffer,
			attributes::queen
		};
	}

	Entity makeSpiderSoldier(iPoint pos)
	{
		return Entity{
			pos,
			'*',
			4,
			"spider soldier",
			brain::blindSniffer,
			attributes::soldier
		};
	}


	Entity makeGoblinGrunt(iPoint pos)
	{
		return Entity{
			pos,
			'G',
			3,
			"gobln grunt",
			brain::randMover,
			attributes::grunt
		};
	}

	Entity makeGoblinWorker(iPoint pos)
	{
		return Entity{
			pos,
			'G',
			3,
			"gobln grunt",
			brain::randMover,
			attributes::worker
		};
	}

	Entity makeHobgoblin(iPoint pos)
	{
		return Entity{
			pos,
			'G',
			3,
			"hobgoblin",
			brain::blindSniffer,
			attributes::soldier
		};
	}

	Entity makeOrcSoldier(iPoint pos)
	{
		return Entity{
			pos,
			'O',
			3,
			"orc soldier",
			brain::blindSniffer,
			attributes::soldier
		};
	}

	Entity makeOrcScout(iPoint pos)
	{
		return Entity{
			pos,
			'O',
			3,
			"orc scout",
			brain::blindSnifferFast,
			attributes::scout
		};
	}

	Entity makeSkeletonWonderer(iPoint pos)
	{
		return Entity{
			pos,
			'k',
			3,
			"skeleton",
			brain::randMover,
			attributes::zombie
		};
	}

	Entity makeZombie(iPoint pos)
	{
		return Entity{
			pos,
			'k',
			3,
			"zombie",
			brain::blindSniffer,
			attributes::zombie
		};
	}

	Entity makeZombieJuggernaut(iPoint pos)
	{
		return Entity{
			pos,
			'K',
			3,
			"zombie juggernaut",
			brain::blindSniffer,
			attributes::zombieJuggernaut
		};
	}
}