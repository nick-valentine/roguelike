#ifndef LEVELPASS_ENEMIES_H
#define LEVELPASS_ENEMIES_H

#include "abstract.h"
#include "../objects/entity.h"

namespace levelPass
{
	class Enemies : public Abstract
	{
	public:
		Enemies(int count);
		virtual ~Enemies() = default;

		virtual void execute(objects::Level &l);
	private:
		void spawnEnemy(objects::Level &l);
		objects::Entity spawn(iPoint where);
		int mCount = 5;
	};
}

#endif // LEVELPASS_ENEMIES_H