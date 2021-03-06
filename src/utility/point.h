#ifndef UTILITY_POINT_H
#define UTILITY_POINT_H

namespace utility
{
	template <typename T>
	class Point
	{
	public:
		Point() = default;
		Point(T x, T y);
		T x;
		T y;
	};

	template <typename T>
	Point<T>::Point(T x, T y) : x(x), y(y)
	{
	}

	template <typename T>
	bool operator==(const Point<T> &a, const Point<T> &b) 
	{
		return a.x == b.x && a.y == b.y;
	}

	template <typename T>
	bool operator!=(const Point<T> &a, const Point<T> &b) 
	{
		return !(a==b);
	}

	using iPoint = Point<int>;
}

#endif // UTILITY_POINT_H