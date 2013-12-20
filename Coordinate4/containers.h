#if !defined(CONTAINERS_H)
#define CONTAINERS_H

#include <array>

#include "algorithms.h"

/*
Derives Array<T, N> class from std::array<T, N> (without any user defined ctor?).
Overloads member operators for Array<T, N>.
Derives Point2D<T> class from Array<T, 2>.
Defines custom ctor for Point2D<T> taking Array<T, 2> as an argument even though it
SHOULD NOT.

Good:
?Can do aggregate instantiation of Array<T, N> like std::array<T, N>.
?Instantiation is easy aggregate initialization; as good as coordinate1.
Overloaded operators for Array<T, N> still works works for derived classes.
Overloaded member operators works outside of the namespace.

Bad:
Aggregate initialization of the base class is NOT working once the class is derived.
Array<T, N> needs ctors.

So far, this seems the best approach.
NOTE: Since std::array<T, N> cannot be used with std::initialization_list<T> or a move ctor,
there is not much benefit to implement them for its derived classes.
*/

namespace Imaging
{
	template <typename T, std::size_t N>
	class Array : public std::array<T, N>
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");
	public:
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
	};
}

#include "containers_inl.h"

#endif
