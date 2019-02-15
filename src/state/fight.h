#ifndef STATE_FIGHT_H
#define STATE_FIGHT_H

#include "abstract.h"
#include "../component/menu.h"
#include "../objects/entity.h"
#include "../objects/entityAttribute.h"

namespace state
{
	class Fight : public Abstract
	{
	public:
		Fight(const objects::Entity *player, objects::EntityAttribute *playerStats, const objects::Entity *other);
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
		component::Menu mActionMenu;
		const objects::Entity *mPlayer;
		const objects::Entity *mOther;
		objects::EntityAttribute *mPlayerStats;
	};
}

#endif // STATE_FIGHT_H