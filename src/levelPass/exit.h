#ifndef LEVELPASS_EXIT_H
#define LEVELPASS_EXIT_H

#include "abstract.h"

namespace levelPass
{
	class Exit : public Abstract
	{
	public:
		virtual ~Exit() = default;

		virtual void execute(objects::Level &l);
	private:
	};
}

#endif // LEVELPASS_EXIT_H