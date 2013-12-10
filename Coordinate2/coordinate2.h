#if !defined(COORDINATE2_H)
#define COORDINATE2_H

#include <array>

/*
Defines Point2D class derived from std::array<T, 2>.
Defines custom ctor taking std::array<T, 2> as an argument even though it SHOULD NOT.

Good:
Instantiation is easy using std::array<T, 2>; as good as coordinate1.
Operators overloaded for std::array<T, N> still works for this class.

Bad:
The overloaded operators for std::array<T, N> works only within the namespace.
*/

namespace Imaging
{
	template <typename T>
	class Point2D : public std::array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported.");
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

	protected:

	};
}

#include "coordinate2_inl.h"

#endif
