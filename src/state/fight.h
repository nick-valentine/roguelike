#ifndef STATE_FIGHT_H
#define STATE_FIGHT_H

#include "abstract.h"
#include "../component/menu.h"
#include "../objects/entity.h"
#include "../objects/entityAttribute.h"

namespace state
{
	struct damageType
	{
		bool physical = false;
		bool magicka = false;
	};

	class Fight : public Abstract
	{
	public:
		Fight(const objects::Entity *player, objects::EntityAttribute *playerStats, const objects::Entity *other);
		void update(Context *ctx);
		void render(window::ptr &win);
	private:
		bool doTurn(int weapon);
		void attack(std::string attackeeName, int weapon, objects::EntityAttribute *attacker, objects::EntityAttribute *attackee);
		void reportTurn();
		void reportEnemy();
		void reportSelf();

		std::vector<std::string> mOptions;
		component::Menu mActionMenu;
		const objects::Entity *mPlayer;
		const objects::Entity *mOther;
		objects::EntityAttribute *mPlayerStats;
		objects::EntityAttribute mOtherStats;
	};
}

#endif // STATE_FIGHT_H