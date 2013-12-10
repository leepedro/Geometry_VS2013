#if !defined(COORDINATE2_H)
#define COORDINATE2_H

#include <array>

/*
Derives Point2D<T> class from std::array<T, 2>.
Overloads non-member operators for std::array<T, N>.
Defines custom ctor taking std::array<T, 2> as an argument even though it SHOULD NOT.

Good:
Instantiation is easy using std::array<T, 2>; as good as coordinate1.
Operators overloaded for std::array<T, N> still works for derived classes.

Bad:
The overloaded operators for std::array<T, N> works only within the namespace.
*/

namespace Imaging
{
	template <typename T>
	class Point2D : public std::array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Point2D(void);
		Point2D(const Point2D<T> &src);
		Point2D(Point2D<T> &&src);
		Point2D &operator=(Point2D<T> src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Point2D(const std::array<T, 2> &srcData);
		Point2D(std::array<T, 2> &&srcData);

		T &x, &y;
	};

	template <typename T>
	class Size2D : public std::array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Size2D(void);
		Size2D(const Size2D<T> &src);
		Size2D(Size2D<T> &&src);
		Size2D &operator=(Size2D<T> src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Size2D(const std::array<T, 2> &srcData);
		Size2D(std::array<T, 2> &&srcData);
		//Size2D &operator=(std::array<T, 2> srcData);

		T &width, &height;
	};
}

#include "coordinate2_inl.h"

#endif
