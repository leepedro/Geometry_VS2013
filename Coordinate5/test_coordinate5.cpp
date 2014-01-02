#include <iostream>

#include "array_utilities5.h"
#include "coordinate5.h"

void TestSafeOperations(void)
{
	int i1 = 1, i2 = 2, i3, i_max = std::numeric_limits<int>::max();
	unsigned int ui1 = 1, ui2 = 2, ui3;
	long long l1 = 1, l2 = 2, l3;
	unsigned long long ul1 = 1, ul2 = 2;
	float f1 = 1.0f, f2 = 2.0f, f3;
	double d1 = 1.0, d2 = 2.0, d3;

	////////////////////////////////////////////////////////////////////////////////////////
	// Addition unsafe operations.
	i3 = i_max + i1;	// overflow risk without warning!
	ui3 = i1 + ui2;		// same width with cross sign; overflow risk without warning!
	i3 = i1 + ui2;		// same width with cross sign; overflow risk without warning!
	i3 = i1 + l2;		// narrowing; data loss risk with warning
	f3 = f1 + d2;		// narrowing; data loss risk with warning
	f3 = f1 + i2;		// same width floating; data loss risk without warning!?
	d3 = d1 + l2;		// same width floating; data loss risk without warning!?
	i3 = f1 + i2;		// floating to integral; data loss risk with warning

	using namespace Imaging;
	////////////////////////////////////////////////////////////////////////////////////////
	// Addition safe operations.
	// Function arguments can be either (T, U, U&) or (T, U, T&).

	// integral and integral
	Add(i1, i2, i3);	// same type
	Add(i1, ui2, ui3);	// same width with cross sign; Okay because safeint checks overflow.
	Add(ui1, i2, ui3);	// same width with cross sign; Okay because safeint checks overflow.
	Add(ui1, i2, i3);	// same width with cross sign; Okay because safeint checks overflow.
	Add(i1, ui2, i3);	// same width with cross sign; Okay because safeint checks overflow.
	Add(i1, l2, l3);	// widening
	Add(l1, i2, l3);	// widening
	Add(i1, l2, i3);	// narrowing; Okay because safeint checks overflow.
	Add(l1, i2, i3);	// narrowing; Okay because safeint checks overflow.

	// floating and floating
	Add(f1, f2, f3);	// same type
	Add(f1, d2, d3);	// widening
	Add(d1, f2, d3);	// widening
	//Add(d1, f2, f3);	// narrowing; Disabled for data loss risk.
	//Add(f1, d2, f3);	// narrowing; Disabled for data loss risk.

	// integral and floating
	Add(i1, d2, d3);	// widening floating
	Add(d1, i2, d3);	// widening floating
	Add(ui1, d2, d3);	// widening floating
	Add(d1, ui2, d3);	// widening floating
	//Add(i1, f2, f3);	// same width floating; Disabled for data loss risk.
	//Add(f1, i2, f3);	// same width floating; Disabled for data loss risk.
	//Add(ui1, f2, f3);	// same width floating; Disabled for data loss risk.
	//Add(f1, ui2, f3);	// same width floating; Disabled for data loss risk.
	//Add(l1, f2, l3);	// floating to integral; Disabled for data loss risk.
	//Add(f1, l2, l3);	// floating to integral; Disabled for data loss risk.

	////////////////////////////////////////////////////////////////////////////////////////
	// Multiplication safe operations.
	// Restriction is identical to addition.
	Multiply(i2, i1, i3);
	Multiply(i2, ui1, ui3);
	Multiply(ui2, i1, ui3);
	Multiply(ui2, i1, i3);
	Multiply(i2, ui1, i3);
	Multiply(i2, l1, l3);
	Multiply(l2, i1, l3);
	Multiply(i2, l1, i3);
	Multiply(l2, i1, i3);
	Multiply(f2, f1, f3);
	Multiply(f2, d1, d3);
	Multiply(d2, f1, d3);
	Multiply(i2, d1, d3);
	Multiply(d2, i1, d3);
	Multiply(ui2, d1, d3);
	Multiply(d2, ui1, d3);

	////////////////////////////////////////////////////////////////////////////////////////
	// Subtraction safe operations.
	// NOTE: Function arguments must be (T, U, T&).

	Subtract(i2, i1, i3);
	//Subtract(i2, ui1, ui3);
	Subtract(ui2, i1, ui3);
	//Subtract(ui2, i1, i3);
	Subtract(i2, ui1, i3);
	//Subtract(i2, l1, l3);
	Subtract(l2, i1, l3);
	Subtract(i2, l1, i3);
	//Subtract(l2, i1, i3);
	Subtract(f2, f1, f3);
	//Subtract(f2, d1, d3);
	Subtract(d2, f1, d3);
	//Subtract(i2, d1, d3);
	Subtract(d2, i1, d3);
	//Subtract(ui2, d1, d3);
	Subtract(d2, ui1, d3);

	double dTemp = 256.0;
	unsigned char ucTemp = Cast<unsigned char>(dTemp);
}

void TestStdArrayInit(void)
{
	// Valid aggregate initialization.
	std::array<int, 2> array1 = { 1, 2 };

	// Compiles with Intellisense warning. It IS valid.
	std::array<int, 2> array2{ 1, 2 };

	// Valid aggregate initialization.
	std::array<int, 2> array3{ { 1, 2 } };

	std::array<long long, 2> arrayL1;
	std::copy(array1.cbegin(), array1.cend(), arrayL1.begin());
	arrayL1 = Imaging::Cast<long long>(array1);
	array1 = Imaging::Cast<int>(arrayL1);
}

void TestArrayUtilitiesSimple(void)
{
	std::array<int, 2> arrayI1 = { 1, 2 }, arrayI2{ 2, 3 }, arrayI3;
	arrayI3 = arrayI1 + arrayI2;
	arrayI3 = arrayI1 + std::array<int, 2>{2, 3};
	arrayI3 = arrayI1 + std::array<int, 2>{{ 2, 3 }};
	std::array<unsigned int, 2> arrayUI1 = { 1, 2 }, arrayUI2{ 2, 3 }, arrayUI3;
	// (T, U, T&) or (T, U, U&)
	Imaging::AddRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayI3.begin());
	Imaging::AddRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayUI3.begin());

	arrayI3 = arrayI2 - arrayI1;
	arrayI3 = arrayI2 - std::array<int, 2>{1, 2};
	arrayI3 = arrayI2 - std::array<int, 2>{{ 1, 2 }};
	// only (T, U, T&)
	Imaging::SubtractRange(arrayI2.cbegin(), arrayI2.cend(), arrayUI1.cbegin(), arrayI3.begin());
	//Imaging::SubtractRange(arrayI2.cbegin(), arrayI2.cend(), arrayUI1.cbegin(), arrayUI3.begin());

	arrayI3 = arrayI1 * arrayI2;
	arrayI3 = arrayI1 * std::array<int, 2>{2, 3};
	arrayI3 = arrayI1 * std::array<int, 2>{{ 2, 3 }};
	// (T, U, T&) or (T, U, U&)
	Imaging::MultiplyRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayI3.begin());
	Imaging::MultiplyRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayUI3.begin());

	arrayI3 = arrayI1 + 2;
	arrayI3 = arrayI1 - 2;
	arrayI3 = arrayI1 * 2;

	arrayI3 += arrayI1;
	Imaging::AddRange(arrayI3.cbegin(), arrayI3.cend(), arrayUI1.cbegin(), arrayI3.begin());

	arrayI3 -= arrayI1;
	Imaging::SubtractRange(arrayI3.cbegin(), arrayI3.cend(), arrayUI1.cbegin(), arrayI3.begin());

	arrayI3 *= arrayI1;
	Imaging::MultiplyRange(arrayI3.cbegin(), arrayI3.cend(), arrayUI1.cbegin(), arrayI3.begin());

	arrayI3 += 2;
	arrayI3 -= 2;
	arrayI3 *= 2;

	++arrayI3;
	arrayI3++;
	--arrayI3;
	arrayI3--;

	//arrayI2 = arrayI1 + arrayUI1;
	std::array<double, 2> arrayD1 = { 1.5, 2.5 };
	arrayI3 = Imaging::RoundAs<int>(arrayD1);
	//std::array<double, 2> arrayD2 = arrayD1 + arrayI1;
	//arrayI2 = arrayI1 + arrayD1;	// C2338 custom compile error. good!
}

template <typename T>
void TestPoint2D_imp(void)
{
	std::cout << "Testing constructors of Point2D<" << typeid(T).name() << ">." << std::endl;

	// (default) Point2D(void)
	Imaging::Point2D<T> pt1;			// NON-ZERO!
	pt1.x = 1, pt1.y = 2;

	// (default) Point2D(const Point2D<T> &)
	Imaging::Point2D<T> pt2 = pt1;

	Imaging::Point2D<T> pt3;
	// (default) Point2D &operator=(const Point2D<T> &)
	pt3 = pt1;

	// Point2D(const Array<T, N> &)
	//Imaging::Array<T, 2> array1{ 5, 6 };
	//Imaging::Point2D<T> pt4(array1);
	//Imaging::Point2D<T> pt5 = array1;

	// Point2D<T>(T, T) though uniform initialization.
	Imaging::Point2D<T> pt6({ static_cast<T>(5), static_cast<T>(6) });
	Imaging::Point2D<T> pt7 = { 7, 8 };
	Imaging::Point2D<T> pt8{ 9, 10 };
	Imaging::Point2D<T> pt9(11, 12);

	Imaging::Point2D<T> pt10;
	// Point2D(const Array<T, 2> &) + (default) Point2D &operator=(const Point2D<T> &)
	//pt10 = array1;

	// The operators of Array<T, N> work OUTSIDE of the namespace. Great!
	// Note: Using overloaded operators of Array<T> requires a ctor with Array<T>.
	std::cout << "Testing with the operators of Array<" << typeid(T).name() << ", 2>." <<
		std::endl;

	Imaging::Point2D<int> ptInt = { 1, 2 };
	//Imaging::Point2D<T> pt11 = pt1 + ptInt;	// {2, 4}
	//Imaging::Point2D<T> pt12 = pt1 - ptInt;	// {0, 0}
	//Imaging::Point2D<T> pt13 = pt1 * ptInt;	// {1, 4}
	Imaging::Point2D<T> pt11 = pt1 + pt1;	// {2, 4}
	Imaging::Point2D<T> pt12 = pt1 - pt1;	// {0, 0}
	Imaging::Point2D<T> pt13 = pt1 * pt1;	// {1, 4}

	Imaging::Point2D<T> pt14(1, 2), pt15(1, 2), pt16(1, 2);
	//pt14 += ptInt;	// {2, 4}
	//pt15 -= ptInt;	// {0, 0}
	//pt16 *= ptInt;	// {1, 4}
	pt14 += pt1;	// {2, 4}
	pt15 -= pt1;	// {0, 0}
	pt16 *= pt1;	// {1, 4}

	//Imaging::Point2D<T> pt17 = pt1 + static_cast<int>(1);	// {2, 3}
	//Imaging::Point2D<T> pt18 = pt1 - static_cast<int>(1);	// {0, 1}
	//Imaging::Point2D<T> pt19 = pt1 * static_cast<int>(1);	// {1, 2}
	Imaging::Point2D<T> pt17 = pt1 + static_cast<T>(1);	// {2, 3}
	Imaging::Point2D<T> pt18 = pt1 - static_cast<T>(1);	// {0, 1}
	Imaging::Point2D<T> pt19 = pt1 * static_cast<T>(1);	// {1, 2}

	Imaging::Point2D<T> pt20(1, 2), pt21(1, 2), pt22(1, 2);
	//pt20 += static_cast<int>(1);	// {2, 3}
	//pt21 -= static_cast<int>(1);	// {0, 1}
	//pt22 *= static_cast<int>(1);	// {1, 2}
	pt20 += static_cast<T>(1);	// {2, 3}
	pt21 -= static_cast<T>(1);	// {0, 1}
	pt22 *= static_cast<T>(1);	// {1, 2}

	Imaging::Point2D<T> pt23(1, 2), pt24(1, 2), pt25(1, 2), pt26(1, 2);
	++pt23;	// {2, 3}
	pt24++;	// {2, 3}
	--pt25;	// {0, 1}
	pt26--;	// {0, 1}

	bool b1 = pt23 == pt24;		// true
	bool b2 = pt25 != pt26;		// false

	// Point2D(const Point2D<U> &)
	//Imaging::Point2D<T> pt27 = ptInt;

	// Point2D(const Point2D<U> &) + (default) Point2D &operator=(const Point2D<T> &)
	//ptInt = pt27;

	TestPoint2DAsArguments<T>();

	std::cout << "Completed testing Poinr2D<" << typeid(T).name() << ">." << std::endl;
}

template <typename T>
void TestPoint2DAsArguments(void)
{
	// Function arguments.
	std::cout << "Constructors as function arguments" << std::endl;

	Imaging::Point2D<T> pt1 = { 1, 2 };

	// (default) Point2D(const Point2D<T> &) for input argument.
	Imaging::Point2D<T> pt2 = Imaging::TakePoint2DReturn(pt1);
	Imaging::TakePoint2D(pt1);

	// Point2D<T>(T, T) though uniform initialization for input argument.
	Imaging::Point2D<T> pt3 = Imaging::TakePoint2DReturn<T>({ 1, 2 });
	Imaging::TakePoint2D<T>({ 1, 2 });

	// Point2D<T> as const std::array<T, 2> &
	Imaging::TakeArray(pt1);
}

void TestPoint2D(void)
{
	TestPoint2D_imp<int>();
	TestPoint2D_imp<unsigned int>();
	TestPoint2D_imp<long long>();
	TestPoint2D_imp<unsigned long long>();
	TestPoint2D_imp<float>();
	TestPoint2D_imp<double>();
}

void TestROI(void)
{
	Imaging::ROI roi1;
	Imaging::ROI roi2 = { { 0, 0 }, { 64, 32 } };
	Imaging::ROI roi3{ { 0, 0 }, { 64, 32 } };
	if (roi2 == roi3)
		std::cout << "good" << std::endl;
	if (roi2 == Imaging::ROI{{ 0, 0 }, roi3.size})
		std::cout << "good" << std::endl;
	//if (roi2 == { { 0, 0 }, roi3.size })
	//	std::cout << "good" << std::endl;
}

int main(void)
{
	TestSafeOperations();
	TestStdArrayInit();
	TestArrayUtilitiesSimple();
	TestPoint2D();
	TestROI();
}
