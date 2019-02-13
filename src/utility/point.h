#ifndef UTILITY_POINT_H
#define UTILITY_POINT_H

namespace utility
{
	template <typename T>
	class Point
	{
	public:
		Point(T x, T y);
		T x;
		T y;
	};

	template <typename T>
	Point<T>::Point(T x, T y) : x(x), y(y)
	{
	}

	using iPoint = Point<int>;
	using fPoint = Point<float>;
}

#endif // UTILITY_POINT_H