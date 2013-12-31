#include <iostream>

#include "array_utilities5.h"

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

	////////////////////////////////////////////////////////////////////////////////////////
	// Addition safe operations.
	using namespace Imaging;

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

	unsigned int ui0 = 0;
	bool result = msl::utilities::SafeSubtract(ui0, i1, ui3);
	//Subtract(i2, i1, i3);
	//Subtract(i2, ui1, ui3);
	//Subtract(ui2, i1, ui3);
	//Subtract(ui2, i1, i3);
	//Subtract(i2, ui1, i3);
	//Subtract(i2, l1, l3);
	//Subtract(l2, i1, l3);
	//Subtract(i2, l1, i3);
	//Subtract(l2, i1, i3);
	//Subtract(f2, f1, f3);
	//Subtract(f2, d1, d3);
	//Subtract(d2, f1, d3);
	//Subtract(i2, d1, d3);
	//Subtract(d2, i1, d3);
	//Subtract(ui2, d1, d3);
	//Subtract(d2, ui1, d3);
}

void TestStdArrayInit(void)
{
	// Valid aggregate initialization.
	std::array<int, 2> array1 = { 1, 2 };

	// Compiles with Intellisense warning. It IS valid.
	std::array<int, 2> array2{ 1, 2 };

	// Valid aggregate initialization.
	std::array<int, 2> array3{ { 1, 2 } };
}

void TestArrayUtilitiesSimple(void)
{
	std::array<int, 2> arrayI1 = { 1, 2 };
	std::array<int, 2> arrayI2 = arrayI1 + std::array<int, 2>{2, 3};
	std::array<int, 2> arrayI3 = arrayI1 + std::array<int, 2>{{ 2, 3 }};
	std::array<unsigned int, 2> arrayUI1 = { 1, 2 }, arrayUI2;
	std::array<int, 2> arrayI4;
	Imaging::AddRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayI4.begin());
	Imaging::AddRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayUI2.begin());

	//arrayI2 = arrayI1 + arrayUI1;
	std::array<double, 2> arrayD1 = { 1.5, 2.5 };
	//std::array<double, 2> arrayD2 = arrayD1 + arrayI1;
	//arrayI2 = arrayI1 + arrayD1;	// C2338 custom compile error. good!
}

int main(void)
{
	TestSafeOperations();
	TestStdArrayInit();
	TestArrayUtilitiesSimple();
}
