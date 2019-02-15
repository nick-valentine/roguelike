#include "log.h"

#include <iostream>

namespace window
{
	Log::Log(iPoint pos, iPoint size) : Curses(pos, size)
	{
		mLog = std::make_shared<utility::logger::Log>();
	}

	void Log::render()
	{
		Curses::clear();
		auto buffer = mLog->buffer();
		auto size = buffer.size();

		auto width = this->size().x;
		auto posMarker = this->size().y - 1;

		auto rit = buffer.rbegin();
		for (;rit != buffer.rend() && posMarker > 0; ++rit) {
			posMarker -= ((*rit).second.size() / width) + 1;
			this->putstr(iPoint(1, posMarker), (*rit).second, 2 /*(int)(*rit).first */);
		}
		Curses::render();
	}

	utility::logger::ptr Log::log()
	{
		return mLog;
	}
}