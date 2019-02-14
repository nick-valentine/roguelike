#ifndef UTILITY_MATRIX_H
#define UTILITY_MATRIX_H

#include <vector>
#include "point.h"

namespace utility
{
	template <typename T>
	using Matrix = std::vector< std::vector<T> >;

	namespace matrix
	{
		template <typename T>
		void fill(Matrix<T> &m, utility::iPoint size, T v)
		{
			m.clear();
			m.resize(size.x, std::vector<T>());
			for (auto &i : m) {
				i.resize(size.y, v);
			}
		}
	}
}

#endif // UTILITY_MATRIX_H