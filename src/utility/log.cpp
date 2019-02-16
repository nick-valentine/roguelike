#include "log.h"

namespace utility::logger
{
	const std::string Log::levelStrings[4] = {
	    "DEBUG",
	    "INFO",
	    "WARNING",
	    "ERROR" 
};

	void Log::setCapacity(int cap)
	{
		mCapacity = cap;
	}

	void Log::setLevel(Level level)
	{
		mLogLevel = level;
	}

	void Log::debug(const char *fmt, ...)
	{
		va_list args;
		va_start (args, fmt);
		this->add(Level::DEBUG, fmt, args);
		va_end(args);
	}

	void Log::info(const char *fmt, ...)
	{
		va_list args;
		va_start (args, fmt);
		this->add(Level::INFO, fmt, args);
		va_end(args);
	}

	void Log::warn(const char *fmt, ...)
	{
		va_list args;
		va_start (args, fmt);
		this->add(Level::WARN, fmt, args);
		va_end(args);
	}

	void Log::error(const char *fmt, ...)
	{
		va_list args;
		va_start (args, fmt);
		this->add(Level::ERROR, fmt, args);
		va_end(args);
		exit(1);
	}

	void Log::log(Level level, const char *fmt, ...)
	{
		va_list args;
		va_start (args, fmt);
		this->add(level, fmt, args);
		va_end(args);
		if (level == Level::ERROR) {
			exit(1);
		}
	}

	std::list<Entry> &Log::buffer()
	{
		return mBuffer;
	}

	void Log::add(Level level, const char *fmt, va_list args)
	{
		if (level <= mLogLevel) {
	        mBuffer.push_back(
	            Entry (
	                level,
	                this->formatString(level, fmt, args)
	            )
	        );
	        while (mBuffer.size() > mCapacity) {
	            mBuffer.pop_front();
	        }
		}
	}

	std::string Log::formatString(Level level, const char *fmt, va_list args)
	{
	    char b[256];
	    vsnprintf(b, 255, fmt, args);
	    std::string formatted = "[" + Log::levelStrings[(int)level - 1] + "] ";
	    formatted += b;
	    return formatted;
	}

}