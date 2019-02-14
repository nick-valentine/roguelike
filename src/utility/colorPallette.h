#ifndef UTILITY_COLLORPALLETTE_H
#define UTILITY_COLLORPALLETTE_H

#include <array>
#include <exception>
#include <curses.h>

namespace utility
{
	class ColorOverflow : public std::exception
	{
	public:
		virtual char const *what() const noexcept
		{
			return "Too many colors were initialized into a pallette";
		}
	};

	class ColorPallette
	{
	public:
		void addColor(uint fg, uint bg);
		void activate();
	private:
		static constexpr uint NumColors = 8;

		uint mTop = 0;
		std::array<uint, NumColors> mFG;
		std::array<uint, NumColors> mBG;
	};
}

#endif // UTILITY_COLLORPALLETTE_H