#include <iostream>

#include "coordinate3.h"

void TestStdArray(void)
{
	// Valid aggregate initialization.
	std::array<int, 2> array1 = { 1, 2 };

	// Compiles with Intellisense warning. It IS valid.
	std::array<int, 2> array2{ 1, 2 };

	// Valid aggregate initialization.
	std::array<int, 2> array3{ { 1, 2 } };
}

void TestArraySimple(void)
{
	// Valid aggregate initialization.
	Imaging::Array<int, 2> coord1 = { 1, 2 };

	// Compiles with Intellisense warning. It IS valid.
	Imaging::Array<int, 2> coord2{ 3, 4 };

	// Compiles with Intellisense warning. It IS valid.
	Imaging::Array<int, 2> coord3{ { 3, 4 } };
}

template <typename T>
void TestArray(void)
{
	// Default (undefined) ctor
	Imaging::Array<T, 2> array1;	// NON-ZERO!

	// Brace/Aggregate initialization.
	Imaging::Array<T, 2> array2 = { 1, 2 };
	Imaging::Array<T, 2> array3{ 3, 4 };

	// Following generates "C2078: too many initializers". Good!
	//Imaging::Array<T, 2> array4{ 3, 4, 5 };	// C2078: too many initializers
	
	// The operators work OUTSIDE of the namespace. Great!

	// Array<T, N> operator+(const Array<U, N> &) const
	Imaging::Array<int, 2> arrayInt = { 1, 2 };
	Imaging::Array<T, 2> array4 = array2 + arrayInt;	// {2, 4}

	// void operator+=(const Array<U, N> &)
	Imaging::Array<T, 2> array5 = { 1, 2 };
	array5 += arrayInt;	// {2, 4}

	// std::enable_if_t<std::is_arithmetic<U>::value, Array<T, N>> operator+(U) const
	Imaging::Array<T, 2> array6 = array2 + static_cast<int>(2);	// {3, 4}

	// std::enable_if_t<std::is_arithmetic<U>::value, void> operator+=(U)
	Imaging::Array<T, 2> array7 = { 1, 2 };
	array7 += static_cast<T>(2);	// {3, 4}

	std::cout << std::endl;
}

template <typename T>
void TestPoint2D(void)
{
	// Point2D(void)
	Imaging::Point2D<T> pt1;
	pt1.x = 1, pt1.y = 2;

	// Point2D(const Point2D<T> &)
	Imaging::Point2D<T> pt2 = pt1;

	// Point2D &operator=(const Point2D<T> &)
	pt1.x = 10;
	pt2 = pt1;

	// Point2D(const Array<T, N> &)
	// This works because Array<T, N> can take aggregate initialization.
	Imaging::Point2D<T> pt3({ 3, 4 });
	Imaging::Array<T, 2> array1{ 5, 6 };
	Imaging::Point2D<T> pt4(array1);
	Imaging::Point2D<T> pt5 = array1;

	// working with Point2D<T>(T, T) or Point2D(const std::initializer_list<T> &).
	Imaging::Point2D<T> pt6 = { 11, 12 };

	// Point2D &operator=(const Array<T, 2> &) or
	// Point2D(const Array<T, N> &) + Point2D &operator=(const Point2D<T> &)
	pt5 = array1;

	// The operators of Array<T, N> work OUTSIDE of the namespace. Great!
	// Note: Using overloaded operators of Array<T> requires a ctor with Array<T>.

	// Array<T, N> operator+(const Array<U, N> &) const +
	// Point2D(const Array<T, 2> &) +
	// Point2D &operator=(const Point2D<T> &)
	pt5 = pt1 + pt1;

	Imaging::Point2D<T> pt7 = Imaging::FuncA(pt1, { 1, 2 });
	std::cout << std::endl;
}

int main(void)
{
	TestStdArray();

	TestArray<int>();				// T = int, U = int
	TestArray<unsigned short>();	// T = unsigned short, U = int
	TestArray<double>();			// T = double, U = int

	TestPoint2D<int>();
	TestPoint2D<double>();

	// Following line generates C2338 with customized error message. GREAT!
	// This is better than std::enable_if<T> from <type_traits>.
	//TestPoint2D<std::string>();
}