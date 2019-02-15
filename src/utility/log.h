#ifndef UTILITY_LOG_H
#define UTILITY_LOG_H

#include <cstring>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <utility>
#include <string>
#include <list>

namespace utility::logger
{

    enum class Level {
        NONE = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4
    };

	class Null;

	using ptr = std::shared_ptr<Null>;
	using Entry = std::pair<Level, std::string>;

	class Null
	{
	public:
		void setCapacity(int cap){};
		void setLevel(Level level){};

		virtual void debug(const char *fmt, ...){};
		virtual void info(const char *fmt, ...){};
		virtual void warn(const char *fmt, ...){};
		virtual void error(const char *fmt, ...){};
		virtual void log(Level level, const char *fmt, ...){};

		virtual std::list<Entry> &buffer(){};
	private:
	};

	class Log : public Null
	{
	public:
		void setCapacity(int cap);
		void setLevel(Level level);

		virtual void debug(const char *fmt, ...);
		virtual void info(const char *fmt, ...);
		virtual void warn(const char *fmt, ...);
		virtual void error(const char *fmt, ...);
		virtual void log(Level level, const char *fmt, ...);

		virtual std::list<Entry> &buffer();
	private:
		const static std::string levelStrings[4];
		virtual void add(Level level, const char *fmt, va_list args);
		virtual std::string formatString(Level level, const char *fmt, va_list args);

		Level mLogLevel = Level::ERROR;
		int mCapacity = 50;
		std::list<Entry> mBuffer;
	};
}

#endif // UTILITY_LOG_H