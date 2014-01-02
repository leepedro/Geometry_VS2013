#if !defined(ARRAY_UTILITIES_H)
#define ARRAY_UTILITIES_H

/*
This header file declares and defines operators for std::array<T, N>.
The operators are defined under global namespace for easier use. (maybe a bad idea?)
*/

/* Operations between containers with different data types.
C++ does not support operations between containers with different data types, so custom
feature needs to be implemented.
Function overload is a good way to do this.
Since C++ cannot overload different functions for different return data types, it is
necessary to place return value at the function parameter list and return it as a reference.

Define operators for only the same type operations.
Use the functions defined in algorithm.h for different data types. ???
Pre-cast source arrays to temporary variables with destination type, and then run the
operation with the temporary variables.
*/

#include <array>

#include "algorithms5.h"

/* Reusing {+=, -=, *=} operators for {+, -, *}.
Copy ctor of std::array is no more expensive than default ctor.

Create result array by copying lhs and then run the assignment operators. */

// C = A + B
template <typename T, std::size_t N>
std::array<T, N> operator+(const std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	std::array<T, N> result = lhs;
	result += rhs;
	return result;
}

// C = A - B
template <typename T, std::size_t N>
std::array<T, N> operator-(const std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	std::array<T, N> result = lhs;
	result -= rhs;
	return result;
}

// C = A * B
template <typename T, std::size_t N>
std::array<T, N> operator*(const std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	std::array<T, N> result = lhs;
	result *= rhs;
	return result;
}

// C = A + b
template <typename T, std::size_t N>
std::array<T, N> operator+(const std::array<T, N> &lhs, T rhs)
{
	std::array<T, N> result = lhs;
	result += rhs;
	return result;
}

// C = A - b
template <typename T, std::size_t N>
std::array<T, N> operator-(const std::array<T, N> &lhs, T rhs)
{
	std::array<T, N> result = lhs;
	result -= rhs;
	return result;
}

// C = A * b
template <typename T, std::size_t N>
std::array<T, N> operator*(const std::array<T, N> &lhs, T rhs)
{
	std::array<T, N> result = lhs;
	result *= rhs;
	return result;
}

// A += B
template <typename T, std::size_t N>
std::array<T, N> &operator+=(std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	Imaging::AddRange(rhs.cbegin(), rhs.cend(), lhs.begin());
	return lhs;
}

// A -= B
template <typename T, std::size_t N>
std::array<T, N> &operator-=(std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	Imaging::SubtractRange(rhs.cbegin(), rhs.cend(), lhs.begin());
	return lhs;
}

// A *= B
template <typename T, std::size_t N>
std::array<T, N> &operator*=(std::array<T, N> &lhs, const std::array<T, N> &rhs)
{
	Imaging::MultiplyRange(rhs.cbegin(), rhs.cend(), lhs.begin());
	return lhs;
}

// A += b
template <typename T, std::size_t N>
std::array<T, N> &operator+=(std::array<T, N> &lhs, T rhs)
{
	for (auto &value : lhs)
		Imaging::Add(value, rhs, value);
	return lhs;
}

// A -= b
template <typename T, std::size_t N>
std::array<T, N> &operator-=(std::array<T, N> &lhs, T rhs)
{
	for (auto &value : lhs)
		Imaging::Subtract(value, rhs, value);
	return lhs;
}

// A *= b
template <typename T, std::size_t N>
std::array<T, N> &operator*=(std::array<T, N> &lhs, T rhs)
{
	for (auto &value : lhs)
		Imaging::Multiply(value, rhs, value);
	return lhs;
}

// ++A
template <typename T, std::size_t N>
std::array<T, N> &operator++(std::array<T, N> &rhs)
{
	for (auto &value : rhs)
		Imaging::Increment(value);
	return rhs;
}

// A++
template <typename T, std::size_t N>
std::array<T, N> operator++(std::array<T, N> &lhs, int)
{
	std::array<T, N> temp = lhs;
	++lhs;
	return temp;
}

// --A
template <typename T, std::size_t N>
std::array<T, N> &operator--(std::array<T, N> &rhs)
{
	for (auto &value : rhs)
		Imaging::Decrement(value);
	return rhs;
}

// A--
template <typename T, std::size_t N>
std::array<T, N> operator--(std::array<T, N> &lhs, int)
{
	std::array<T, N> temp = lhs;
	--lhs;
	return temp;
}

namespace Imaging
{
	template <typename T, typename U, std::size_t N>
	std::enable_if_t<std::is_floating_point<U>::value, std::array<T, N>> RoundAs(
		const std::array<U, N> &src)
	{
		std::array<T, N> dst;
		auto itDst = dst.begin(), itDstEnd = dst.end();
		for (auto itSrc = src.begin(); itDst != itDstEnd; ++itDst, ++itSrc)
			*itDst = Cast<T>(std::round(*itSrc));
		return dst;
	}

	template <typename T, typename U, std::size_t N>
	std::array<T, N> Cast(const std::array<U, N> &src)
	{
		std::array<T, N> dst;
		auto itDst = dst.begin(), itDstEnd = dst.end();
		for (auto itSrc = src.begin(); itDst != itDstEnd; ++itDst, ++itSrc)
			*itDst = Cast<T>(*itSrc);
		return dst;
	}
}
#endif
