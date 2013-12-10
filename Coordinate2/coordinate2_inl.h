#if !defined(COORDINATE2_INL_H)
#define COORDINATE2_INL_H

namespace Imaging
{
	// Even though this ctor does not explicitly take any action on data_,
	// it initializes all members.
	// If you want to initialize any member in a different way, you should not call
	// this ctor as a delegation ctor.
	template <typename T>
	Point2D<T>::Point2D(void) : x(this->at(0)), y(this->at(1)) {}

	template <typename T>
	Point2D<T>::Point2D(const Point2D<T> &src) :
		x(this->at(0)), y(this->at(1)), std::array<T, 2>(src) {}

	template <typename T>
	Point2D<T>::Point2D(Point2D<T> &&src) : Point2D<T>()
	{
		this->swap(src);
	}

	// This operator=(Point2D<T>) replaces both operator=(const Point2D<T> &) and
	// operator=(Point2D<T> &&) by using copy and swap idiom.
	template <typename T>
	Point2D<T> &Point2D<T>::operator=(Point2D<T> src)
	{
		this->swap(src);
		return *this;
	}

	template <typename T>
	Point2D<T>::Point2D(const std::array<T, 2> &srcData) :
		x(this->at(0)), y(this->at(1)), std::array<T, 2>(srcData) {}

	template <typename T>
	Point2D<T>::Point2D(std::array<T, 2> &&srcData) : Point2D<T>()
	{
		this->swap(srcData);
	}
}

#endif
