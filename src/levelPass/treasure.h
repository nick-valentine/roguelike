#ifndef LEVELPASS_TREASURE_H
#define LEVELPASS_TREASURE_H

#include "abstract.h"
#include "../objects/entity.h"

namespace levelPass
{
	class Treasure : public Abstract
	{
	public:
		Treasure(int count, int mLevel);
		virtual ~Treasure() = default;

		virtual void execute(objects::Level &l);
	private:
		void spawnTreasure(objects::Level &l);
		int mCount = 5;
		int mLevel = 1;
	};
}

#endif // LEVELPASS_TREASURE_H