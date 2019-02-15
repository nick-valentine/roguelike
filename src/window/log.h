#ifndef WINDOW_LOG_H
#define WINDOW_LOG_H

#include <curses.h>
#include <list>
#include <string>

#include "curses.h"
#include "../utility/log.h"

namespace window
{
	class Log : public Curses
	{
	public:
		Log(iPoint pos, iPoint size);
		virtual void render();
		utility::logger::ptr log();
	private:
		utility::logger::ptr mLog;
	};
}

#endif // WINDOW_LOG_H