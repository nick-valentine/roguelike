#include "colorPallette.h"

namespace utility
{
	void ColorPallette::addColor(uint fg, uint bg)
	{
		mFG[mTop] = fg;
		mBG[mTop] = bg;
		mTop++;
		if (mTop > ColorPallette::NumColors) {
			throw ColorOverflow();
		}
	}

	void ColorPallette::activate()
	{
		if (has_colors()) {
			for (uint i = 0; i < mTop; ++i) {
				init_pair(i+1, mFG[i], mBG[i]);
			}
		}
	}
}