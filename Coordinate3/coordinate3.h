#if !defined(COORDINATE3_H)
#define COORDINATE3_H

#include <array>
#include <stdexcept>
#include <safeint.h>

/*
Defines Coordinate<T, N> class without any user defined ctor.
Declares an std::array<T, 2> as a public member and it must be the only member.
Overloads member operators for Coordinate<T, N>.
Derives Point2D<T> class from Coordinate<T, 2>.
Defines custom ctor for Point2D<T> taking Coordinate<T, 2> as an argument even though it
SHOULD NOT.

Good:
Can do aggregate instantiation of Coordinate<T, N> like std::array<T, N>.
Instantiation is easy aggregate initialization; as good as coordinate1.
Overloaded operators for Coordinate<T, N> still works works for derived classes.
Overloaded member operators works outside of the namespace.

So far, this seems the best approach.
*/
namespace Imaging
{
	template <typename T, ::size_t N>
	class Coordinate
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Overloaded operators.
		Coordinate<T, N> operator+(const Coordinate<T, N> &other) const;

		std::array<T, N> data;
	};

	template <typename T>
	class Point2D : public Coordinate<T, 2>
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
		Point2D(const Coordinate<T, 2> &src);
		Point2D(Coordinate<T, 2> &&src);

		T &x, &y;

	protected:
		void Swap(Point2D<T> &src);
	};

	template <typename T>
	class Size2D : public Coordinate<T, 2>
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
		Size2D(const Coordinate<T, 2> &src);
		Size2D(Coordinate<T, 2> &&src);

		T &width, &height;
	};
}

#include "coordinate3_inl.h"

#endif
