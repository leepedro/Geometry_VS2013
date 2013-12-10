#if !defined(COORDINATES_H)
#define COORDINATES_H

#include <array>
#include <type_traits>

namespace Imaging
{
	template <typename T>
	class Point2D
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported.");
	public:
		Point2D(void);
		Point2D(const Point2D<T> &src);
		Point2D(Point2D<T> &&src);
		Point2D &operator=(Point2D<T> src);

		Point2D(const std::array<T, 2> &srcData);
		Point2D(std::array<T, 2> &&srcData);
		//Point2D &operator=(std::array<T, 2> srcData);

		T &x, &y;

	protected:
		void Swap(Point2D<T> &src);
		std::array<T, 2> data_;
	};
}

#include "coordinates_inl.h"

#endif
