#if !defined(ARRAY_UTILITIES_H)
#define ARRAY_UTILITIES_H

/*
This header file declares and defines operators for std::array<T, N>.
The operators are defined under global namespace for easier use. (maybe a bad idea?)
*/

/* Operations between different data types.
Since C++ cannot overload different functions for different return data types, it is
necessary to force return argument at function parameter list.
Define operators for only the same type operations.
Use the functions defined in algorithm.h for different data types.
*/
#include <array>

#include "algorithms5.h"

// C = A + B
// array<T,N> = array<T,N> + array<T,N>
template <typename T, std::size_t N>
std::array<T, N> operator+(const std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	std::array<T, N> result;
	Imaging::AddRange(lhs.cbegin(), lhs.cend(), rhs.begin(), result.begin());
	return result;
}

// Cast to the same type and run operator between same type only?
// Define operators for only the same type operations, and use a function for different
// data types.

#endif
