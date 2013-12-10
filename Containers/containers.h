#if !defined(CONTAINERS_H)
#define CONTAINERS_H

#include <array>
#include <stdexcept>
//#include <typeinfo>
#include <safeint.h>

namespace Imaging
{
	template <typename T, ::size_t N>
	void Add(const std::array<T, N> &a, const std::array<T, N> &b, std::array<T, N> &c);

	template <typename T, ::size_t N>
	std::array<T, N> operator+(const std::array<T, N> &a, const std::array<T, N> &b);

}

#include "containers_inl.h"

#endif
