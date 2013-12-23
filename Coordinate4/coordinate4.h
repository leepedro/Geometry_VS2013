#if !defined(COORDINATE4_H)
#define COORDINATE4_H

#include "containers4.h"

namespace Imaging
{
	template <typename T>
	class Point2D : public Array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Point2D(void) = default;
		Point2D &operator=(const Point2D<T> &src) = default;

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Point2D(const Array<T, 2> &srcData);
		Point2D(T x, T y);

		T &x = this->at(0);
		T &y = this->at(1);
	};

	template <typename T>
	Point2D<T> TakePoint2DReturn(const Point2D<T> &src);

	template <typename T>
	void TakePoint2D(const Point2D<T> &src);

	template <typename T>
	class Size2D : public Array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Size2D(void) = default;
		Size2D &operator=(const Size2D<T> &src) = default;

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Size2D(const Array<T, 2> &srcData);
		Size2D(T w, T h);

		T &width = this->at(0);
		T &height = this->at(1);
	};
}

#include "coordinate4_inl.h"

#endif
