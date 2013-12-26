#if !defined(COORDINATE3_H)
#define COORDINATE3_H

#include <array>

#include "algorithms.h"

/*
Defines Array<T, N> class without any user defined ctor.
Declares an std::array<T, 2> as a public member and it must be the only member.
Overloads member operators for Array<T, N>.
Derives Point2D<T> class later from Array<T, 2>.
Defines custom ctor for Point2D<T> taking Array<T, 2> as an argument even though it
SHOULD NOT.

Good:
Can do aggregate instantiation of Array<T, N> like std::array<T, N>.
Overloaded operators for Array<T, N> still works works for derived classes.
Overloaded member operators works outside of the namespace.
Visual Studio debugging interface is slightly more convenient if std::array<T, N> is
a member of Array<T, N> instead of the base class.


NOTE: Since std::array<T, N> cannot be used with a move ctor, there is not much benefit to
implement them for its derived classes.

So far, this seems the best approach.
*/
namespace Imaging
{
	template <typename T, std::size_t N>
	class Array
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Overloaded operators.

		// A = B + C
		template <typename U>
		Array<T, N> operator+(const Array<U, N> &rhs) const;

		// A = B + c
		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, Array<T, N>> operator+(U rhs) const;

		// A += B
		template <typename U>
		void operator+=(const Array<U, N> &rhs);

		// A += b
		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, void> operator+=(U rhs);

		// ++A
		Array<T, N> &operator++(void);

		// A++
		Array<T, N> operator++(int);

		// cast
		//template <typename U>
		//operator Array<U, N>();

		////////////////////////////////////////////////////////////////////////////////////
		// Members.
		std::array<T, N> data;
	};

	template <typename T, std::size_t N>
	Array<T, 2> TakeArrayReturn(const Array<T, N> &src);

	template <typename T, std::size_t N>
	void TakeArray(const Array<T, N> &src);


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
		Point2D(const Point2D<T> &src) = default;	// optional

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		template <typename U>
		Point2D(const Point2D<U> &src);

		Point2D(const Array<T, 2> &srcData);
		Point2D(T x, T y);

		T &x = this->data.at(0);
		T &y = this->data.at(1);
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
		Size2D(const Array<T, 2> &src);
		Size2D(T w, T h);

		T &width = this->data.at(0);
		T &height = this->data.at(1);
	};
}

#include "coordinate3_inl.h"

#endif
