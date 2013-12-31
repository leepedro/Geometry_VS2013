#include <iostream>

#include "array_utilities5.h"

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
	//Imaging::AddRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayI4.begin());
	Imaging::AddRange(arrayI1.cbegin(), arrayI1.cend(), arrayUI1.cbegin(), arrayUI2.begin());

	//arrayI2 = arrayI1 + arrayUI1;
	std::array<double, 2> arrayD1 = { 1.5, 2.5 };
	//std::array<double, 2> arrayD2 = arrayD1 + arrayI1;
	//arrayI2 = arrayI1 + arrayD1;	// C2338 custom compile error. good!
}

int main(void)
{
	TestStdArrayInit();
	TestArrayUtilitiesSimple();
}
