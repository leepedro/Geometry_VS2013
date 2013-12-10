#if !defined(COORDINATE3_H)
#define COORDINATE3_H

#include <array>

namespace Imaging
{
	// Array class may inherit std::array<> or may take std::array<> as a member.
	// Array class is mainly for operator overloading.
	template <typename T, ::size_t N>
	class Array : public std::array<T, N>
	{
		static_assert(std::is_arithmetic<T>::value,
			"Only arithmetic data types are supported.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Array(void);
		Array(const Array<T, N> &src);
		Array(Array<T, N> &&src);
		Array<T, N> &operator=(Array<T, N> src);

		////////////////////////////////////////////////////////////////////////////////////
		// Overloaded operators.
		Array<T, N> operator+(const Array<T, N> &pt);
	};

	template <typename T>
	class Point2D : public Array<T, 2>
	{

	};
}

#endif
