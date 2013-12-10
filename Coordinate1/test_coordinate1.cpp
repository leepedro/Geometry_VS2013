#include "coordinate1.h"

void TestContainers(void)
{
	std::array<int, 2> array1 = { 1, 2 }, array2 = { 3, 4 };

	// The operator+ works only INSIDE of the namespace.
	using namespace Imaging;
	std::array<int, 2> array3 = array1 + array2;
}

template <typename T>
void TestPoint2D(void)
{
	Imaging::Point2D<T> pt1;	// Default ctor
	pt1.x = 5, pt1.y = 6;

	// std::array<T> examples.
	std::array<T, 2> array1 = { 1, 2 };
	std::array<T, 2> array2{ 3, 4 };

	// ctor Point2D(const std::array<T, 2> &)
	Imaging::Point2D<T> pt2(array1);

	// ctor Point2D(std::array<T, 2> &&)
	Imaging::Point2D<T> pt3(std::array<T, 2>{7, 8});

	// Following line works by implicitly taking two steps.
	// ctor Point2D(const std::array<T, 2> &) + operator=(Point2D<T>)
	pt1 = array2;

	// operator=(Point2D<T> src) implicitly calls ctor Point2D(const Point2D<T> &)
	// during argument evaluation. 
	pt3 = pt1;

	// This works by implicitly taking ctor Point2D(const std::array<T, 2> &)
	Imaging::Point2D<T> pt4({ 9, 10 });

	//Imaging::Point2D<T> pt5 = { 11, 12 };	// NOT working.

	Imaging::Point2D<T> pt5 = pt3 + pt4;
}

int main(void)
{
	TestContainers();

	TestPoint2D<int>();

	// Following line generates C2338 with customized error message. GREAT!
	// This is much better than std::enable_if<T> from <type_traits>.
	//TestPoint2D<std::string>();
}