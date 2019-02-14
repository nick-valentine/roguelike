#ifndef LEVELPASS_ABSTRACT_H
#define LEVELPASS_ABSTRACT_H

#include <memory>

#include "../objects/level.h"

namespace levelPass
{
	class Abstract
	{
	public:
		virtual ~Abstract() = default;

		virtual void execute(objects::Level &l) = 0;
	};
}

#endif // LEVELPASS_ABSTRACT_H