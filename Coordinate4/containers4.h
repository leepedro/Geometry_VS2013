#if !defined(CONTAINERS4_H)
#define CONTAINERS4_H

#include <array>

#include "algorithms.h"

/*
Derives Array<T, N> class from std::array<T, N> without any user defined ctor.
Overloads member operators for Array<T, N>.
Derives Point2D<T> class later from Array<T, 2>.
Defines custom ctor for Point2D<T> taking Array<T, 2> as an argument even though it
SHOULD NOT.

Good:
Overloaded operators for Array<T, N> still works works for derived classes.
Overloaded member operators works outside of the namespace.

Bad:
Aggregate initialization of the base class is NOT working once the class is derived.
Therefore, Array<T, N> needs ctors if you want to actually instantiate and use it.
-> The only purpose of Array<T, N> is to provide overloaded operators, so do NOT instantiate
Array<T, N>. Whether Array<T, N> has an initilizer ctor or not, its derived classes need
their own ctor with an initializer, so why bother to make one.

NOTE: Since std::array<T, N> cannot be used with a move ctor, there is not much benefit to
implement them for its derived classes.
*/

namespace Imaging
{
	// Base class for operators.
	template <typename T, std::size_t N>
	class Array : public std::array<T, N>
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
	};

	template <typename T, std::size_t N>
	void TakeArray(const Array<T, N> &src);
}

#include "containers4_inl.h"

#endif
