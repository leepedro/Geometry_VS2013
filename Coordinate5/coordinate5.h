#if !defined(COORDINATE5_H)
#define COORDINATE5_H

#include <array>

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
		Point2D(void) = default;
		Point2D &operator=(const Point2D<T> &src) = default;

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Point2D(T x, T y);
		Point2D(const std::array<T, 2> &src);

		T &x = this->at(0);
		T &y = this->at(1);
	};

	template <typename T>
	class Size2D : public std::array<T, 2>
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
		Size2D(T width, T height);
		Size2D(const std::array<T, 2> &src);

		T &width = this->at(0);
		T &height = this->at(1);
	};

	template <typename T, typename U>
	class RectTypeB
	{
		static_assert(std::is_arithmetic<T>::value && std::is_arithmetic<U>::value,
		"origin must be integral data type and size must be unsigned integral type.");

	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Operators.
		bool operator==(const RectTypeB<T, U> &rhs) const;
		bool operator!=(const RectTypeB<T, U> &rhs) const;

		////////////////////////////////////////////////////////////////////////////////////
		// Data.
		Point2D<T> origin;
		Size2D<U> size;
	};

	typedef RectTypeB<std::size_t, std::size_t> ROI;

	template <typename T, std::size_t N>
	void TakeArray(const std::array<T, N> &src);

	template <typename T>
	Point2D<T> TakePoint2DReturn(const Point2D<T> &src);

	template <typename T>
	void TakePoint2D(const Point2D<T> &src);
}

#include "coordinate5_inl.h"

#endif
