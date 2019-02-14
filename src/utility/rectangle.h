#ifndef UTILITY_RECTANGLE_H
#define UTILITY_RECTANGLE_H

namespace utility
{
	template <typename T>
	class Rectangle
	{
	public:
		Rectangle(T x, T y, T w, T h);
		T x;
		T y;
		T w;
		T h;
	};

	template <typename T>
	Rectangle<T>::Rectangle(T x, T y, T w, T h) : x(x), y(y), w(w), h(h)
	{
	}

	using iRectangle = Rectangle<int>;
}

#endif // UTILITY_RECTANGLE_H