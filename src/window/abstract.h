#ifndef WINDOW_ABSTRACT_H
#define WINDOW_ABSTRACT_H

#include <string>

#include "../utility/point.h"
#include "utility.h"

using namespace utility;

namespace window {
	class Abstract
	{
	public:
		virtual ~Abstract() = default;

		virtual void putstr(iPoint p, std::string str, int color = 0) = 0;
		virtual void put(uint colorPair, uint layer, char c, iPoint p) = 0;
		virtual void put(TextElement c, iPoint p) = 0;
		virtual void clear() = 0;

		virtual void render() = 0;
		virtual void resize(iPoint size) = 0;
		virtual void move(iPoint to) = 0;

		virtual int getCh() = 0;

		virtual iPoint pos() = 0;
		virtual iPoint size() = 0;
	};
}

#endif // WINDOW_ABSTRACT_H