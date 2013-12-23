#if !defined(COORDINATE3_INL_H)
#define COORDINATE3_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Point2D<T>

	template <typename T>
	Point2D<T>::Point2D(const Array<T, 2> &srcData) : Array<T, 2>(srcData)
	{
		std::cout << "Point2D<T>::Point2D(const Array<T, 2> &)" << std::endl;
	}

	template <typename T>
	Point2D<T>::Point2D(T x, T y) : Point2D<T>()
	{
		std::cout << "Point2D<T>::Point2D(T x, T y)" << std::endl;
		this->x = x;
		this->y = y;
	}

	// Point2D<T>
	////////////////////////////////////////////////////////////////////////////////////

	template <typename T>
	Point2D<T> TakePoint2DReturn(const Point2D<T> &src)
	{
		std::cout << "Point2D<T> TakeArrayReturn(const Point2D<T> &)" << std::endl;
		return{ 1, 2 };
	}

	template <typename T>
	void TakePoint2D(const Point2D<T> &src)
	{
		std::cout << "void TakeArrayReturn(const Point2D<T> &)" << std::endl;
	}
}

#endif
