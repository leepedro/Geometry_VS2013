#include "coordinate3.h"

template <typename T>
void TestCoordinate(void)
{
	Imaging::Coordinate<T, 2> coord1 = { 1, 2 };
	Imaging::Coordinate<T, 2> coord2{ 3, 4 };

	// Following generates "C2078: too many initializers". Good!
	//Imaging::Coordinate<T, 2> coord3{ 3, 4, 5 };	// C2078: too many initializers
	
	// The operator+ works even OUTSIDE of the namespace. Great!
	Imaging::Coordinate<T, 2> coord3 = coord1 + coord2;
}

template <typename T>
void TestPoint2D(void)
{

	Imaging::Point2D<T> pt1;	// Default ctor
	pt1.x = 1, pt1.y = 2;

	// This works by implicitly taking ctor Point2D(const Coordinate<T, 2> &)
	Imaging::Point2D<T> pt2({ 3, 4 });

	// ctor Point2D(const Point2D<T> &) is called WITHOUT operator=(Point2D<T> src).
	Imaging::Point2D<T> pt3 = pt1;

	// operator=(Point2D<T> src) IS called here, and
	// it implicitly called ctor Point2D(const Point2D<T> &).
	pt3 = pt1;

	// Coordinate<T, N> examples.
	Imaging::Coordinate<T, 2> coord1{ 5, 6 };

	// ctor Point2D(const Coordinate<T, 2> &)
	Imaging::Point2D<T> pt4(coord1);
	Imaging::Point2D<T> pt5 = coord1;

	//Imaging::Point2D<T> pt6 = { 11, 12 };	// NOT working.

	// The operator+ works even OUTSIDE of the namespace. Great!
	// This works by implicitly taking ctor Point2D(const Coordinate<T, 2> &)
	Imaging::Point2D<T> pt6 = pt1 + pt1;
}

int main(void)
{
	TestCoordinate<int>();

	TestPoint2D<int>();

	// Following line generates C2338 with customized error message. GREAT!
	// This is much better than std::enable_if<T> from <type_traits>.
	//TestPoint2D<std::string>();
}