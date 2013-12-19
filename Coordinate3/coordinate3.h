#if !defined(COORDINATE3_H)
#define COORDINATE3_H

#include <array>

#include "algorithms.h"

/*
Defines Array<T, N> class without any user defined ctor.
Declares an std::array<T, 2> as a public member and it must be the only member.
Overloads member operators for Array<T, N>.
Derives Point2D<T> class from Coordinate<T, 2>.
Defines custom ctor for Point2D<T> taking Coordinate<T, 2> as an argument even though it
SHOULD NOT.

Good:
Can do aggregate instantiation of Array<T, N> like std::array<T, N>.
Instantiation is easy aggregate initialization; as good as coordinate1.
Overloaded operators for Array<T, N> still works works for derived classes.
Overloaded member operators works outside of the namespace.

So far, this seems the best approach.
NOTE: Since std::array<T, N> cannot be used with std::initialization_list<T> or a move ctor,
there is not much benefit to implement them for its derived classes.
*/
namespace Imaging
{
	template <typename T, ::size_t N>
	class Array
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported for this class template.");
	public:
		/*
		std::array<T, N> cannot be used with std::initialization_list<T>.
		*/
		//Array(const std::initializer_list<T> &srcList);

		////////////////////////////////////////////////////////////////////////////////////
		// Overloaded operators.
		template <typename U>
		Array<T, N> operator+(const Array<U, N> &rhs) const;

		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, Array<T, N>> operator+(U rhs) const;

		template <typename U>
		void operator+=(const Array<U, N> &rhs);

		template <typename U>
		std::enable_if_t<std::is_arithmetic<U>::value, void> operator+=(U rhs);

		////////////////////////////////////////////////////////////////////////////////////
		// Members.
		std::array<T, N> data;
	};

	template <typename T>
	class Point2D : public Array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Point2D(void);
		Point2D(const Point2D<T> &src);
		Point2D &operator=(const Point2D<T> &src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Point2D(const Array<T, 2> &srcData);
		//Point2D &operator=(const Array<T, 2> &srcData);	// optional, no need

		T &x, &y;
	};

	template <typename T>
	class Size2D : public Array<T, 2>
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Size2D(void);
		Size2D(const Size2D<T> &src);
		Size2D &operator=(const Size2D<T> &src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Size2D(const Array<T, 2> &src);
		//Size2D &operator=(const Array<T, 2> &srcData);	// optional, no need

		T &width, &height;
	};
}

#include "coordinate3_inl.h"

#endif
