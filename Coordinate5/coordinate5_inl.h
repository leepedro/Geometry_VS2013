#if !defined(COORDINATE5_INL_H)
#define COORDINATE5_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Point2D<T>

	template <typename T>
	Point2D<T>::Point2D(T x, T y) : Point2D<T>()
	{
		std::cout << "Point2D<T>::Point2D(T, T)" << std::endl;
		this->x = x;
		this->y = y;
	}

	template <typename T>
	Point2D<T>::Point2D(const std::array<T, 2> &src) : std::array<T, 2>(src)
	{
		std::cout << "Point2D<T>::Point2D(const std::array<T, 2> &)" << std::endl;
	}

	// Point2D<T>
	////////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////////
	// Size2D<T>

	template <typename T>
	Size2D<T>::Size2D(T width, T height) : Size2D<T>()
	{
		std::cout << "Size2D<T>::Size2D(T, T)" << std::endl;
		this->width = width;
		this->height = height;
	}

	template <typename T>
	Size2D<T>::Size2D(const std::array<T, 2> &src) : std::array<T, 2>(src)
	{
		std::cout << "Size2D<T>::Size2D(const std::array<T, 2> &)" << std::endl;
	}

	// Size2D<T>
	////////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////////
	// RectTypeB<T, U>

	template <typename T, typename U>
	bool RectTypeB<T, U>::operator==(const RectTypeB<T, U> &rhs) const
	{
		return this->origin == rhs.origin && this->size == rhs.size;
	}

	template <typename T, typename U>
	bool RectTypeB<T, U>::operator!=(const RectTypeB<T, U> &rhs) const
	{
		return !(*this == rhs);
	}

	// RectTypeB<T, U>
	////////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////////
	// Test functions

	template <typename T, std::size_t N>
	void TakeArray(const std::array<T, N> &src)
	{
		std::cout << "void TakeArray(const std::array<T, N> &)" << std::endl;
	}

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

	// Test functions
	////////////////////////////////////////////////////////////////////////////////////
}

#endif
