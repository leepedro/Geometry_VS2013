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
	Imaging::Array<int, 2> array1 = { 1, 2 };

	// Compiles with Intellisense warning. It IS valid.
	Imaging::Array<int, 2> array2{ 3, 4 };

	// Compiles with Intellisense warning. It IS valid.
	Imaging::Array<int, 2> array3{ { 3, 4 } };
}

template <typename T>
void TestArray(void)
{
	std::cout << "Constructors of Array<" << typeid(T).name() << ", N>" << std::endl;

	// (default) Array<T, N>(void)
	Imaging::Array<T, 2> array1;	// NON-ZERO!
	array1.data[0] = 0;

	// Brace/Aggregate initialization.
	Imaging::Array<T, 2> array2 = { 1, 2 };
	Imaging::Array<T, 2> array3{ 3, 4 };
	Imaging::Array<T, 2> array4{ { 5, 6 } };

	// Following generates "C2078: too many initializers". Good!
	//Imaging::Array<T, 2> array4{ 3, 4, 5 };	// C2078: too many initializers
	
	// The operators work OUTSIDE of the namespace. Great!

	// Array<T, N> operator+(const Array<U, N> &) const
	Imaging::Array<int, 2> arrayInt = { 1, 2 };
	Imaging::Array<T, 2> array5 = array2 + arrayInt;	// {2, 4}

	// Array<T, N> operator+(U) const
	Imaging::Array<T, 2> array6 = array2 + static_cast<int>(2);	// {3, 4}

	Imaging::Array<T, 2> array7 = { 1, 2 }, array8 = { 1, 2 }, array9 = { 1, 2 },
		array10 = { 1, 2 };
	// void operator+=(const Array<U, N> &)	
	array7 += arrayInt;				// {2, 4}

	// void operator+=(U)
	array8 += static_cast<T>(2);	// {3, 4}

	// Array<T, N> &operator++(void)
	++array9;						// {2, 3}

	// Array<T, N> operator++(int)
	array10++;						// {2, 3}

	// Function arguments.
	std::cout << "Constructors as function arguments" << std::endl;

	// (default) Array<T, N>(const Array<T, N> &) for input argument.
	Imaging::Array<T, 2> array11 = Imaging::TakeArrayReturn<T, 2>(array1);
	Imaging::TakeArray<T, 2>(array1);

	// Aggregate initialization for input argument.
	Imaging::Array<T, 2> array12 = Imaging::TakeArrayReturn<T, 2>({ 10, 20 });
	Imaging::TakeArray<T, 2>({ 10, 20 });

	std::cout << std::endl;
}

template <typename T>
void TestPoint2D(void)
{
	std::cout << "Constructors of Point2D<" << typeid(T).name() << ">" << std::endl;

	// (default) Point2D(void)
	Imaging::Point2D<T> pt1;		// NON-ZERO!
	pt1.x = 1, pt1.y = 2;

	// (default) Point2D(const Point2D<T> &)
	Imaging::Point2D<T> pt2 = pt1;

	Imaging::Point2D<T> pt3;
	// (default) Point2D &operator=(const Point2D<T> &)
	pt3 = pt1;

	// Point2D(const Array<T, N> &)
	Imaging::Array<T, 2> array1{ 3, 4 };
	Imaging::Point2D<T> pt4(array1);
	Imaging::Point2D<T> pt5 = array1;

	// Point2D<T>(T, T) though uniform initialization.
	Imaging::Point2D<T> pt6({ static_cast<T>(5), static_cast<T>(6) });
	Imaging::Point2D<T> pt7 = { 7, 8 };
	Imaging::Point2D<T> pt8{ 9, 10 };
	Imaging::Point2D<T> pt9(9, 10);

	Imaging::Point2D<T> pt10;
	// Point2D(const Array<T, 2> &) + (default) Point2D &operator=(const Point2D<T> &)
	pt10 = array1;

	// The operators of Array<T, N> work OUTSIDE of the namespace. Great!
	// Note: Using overloaded operators of Array<T> requires a ctor with Array<T>.

	// Array<T, N> operator+(const Array<U, N> &)
	Imaging::Point2D<T> pt11 = pt1 + pt1;

	// Array<T, N>> operator+(U)
	Imaging::Point2D<T> pt12 = pt1 + 2;

	Imaging::Point2D<T> pt13(0, 0), pt14(0, 0), pt15(0, 0), pt16(0, 0);
	// void operator+=(const Array<U, N> &)
	pt13 += pt1;

	// void operator+=(U)
	pt14 += 2;

	// Array<T, N> &operator++(void)
	++pt15;

	// Array<T, N> operator++(int)
	pt16++;

	// Function arguments.
	std::cout << "Constructors as function arguments" << std::endl;

	// (default) Point2D(const Point2D<T> &) for input argument.
	Imaging::Point2D<T> pt17 = Imaging::TakePoint2DReturn(pt1);
	Imaging::TakePoint2D(pt1);

	// Point2D<T>(T, T) though uniform initialization for input argument.
	Imaging::Point2D<T> pt18 = Imaging::TakePoint2DReturn<T>({ 1, 2 });
	Imaging::TakePoint2D<T>({ 1, 2 });

	// Point2D<T> as const Array<T, 2> &
	Imaging::TakeArray(pt1);

	std::cout << std::endl;
}

int main(void)
{
	TestStdArray();

	TestArraySimple();

	TestArray<int>();				// T = int, U = int
	TestArray<unsigned short>();	// T = unsigned short, U = int
	TestArray<float>();				// T = float, U = int
	TestArray<double>();			// T = double, U = int

	TestPoint2D<int>();
	TestPoint2D<float>();
	TestPoint2D<double>();

	// Following line generates C2338 with customized error message. GREAT!
	// This is better than std::enable_if<T> from <type_traits>.
	//TestPoint2D<std::string>();
}