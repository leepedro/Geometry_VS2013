#if !defined(COORDINATE3_INL_H)
#define COORDINATE3_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Coordinate<T, N>

	template <typename T, ::size_t N>
	Coordinate<T, N> Coordinate<T, N>::operator+(const Coordinate<T, N> &other) const
	{
		Coordinate<T, N> result;
		Add(this->data.cbegin(), this->data.cend(), other.data.cbegin(), result.data.begin());
		return result;
	}


	////////////////////////////////////////////////////////////////////////////////////
	// Point2D<T>

	template <typename T>
	Point2D<T>::Point2D(void) :
		Coordinate<T, 2>(), x(this->data.at(0)), y(this->data.at(1)) {}

	template <typename T>
	Point2D<T>::Point2D(const Point2D<T> &src) :
		Coordinate<T, 2>(src), x(this->data.at(0)), y(this->data.at(1)) {}

	template <typename T>
	Point2D<T>::Point2D(Point2D<T> &&src) : Point2D<T>()
	{
		this->Swap(src);
	}

	// This operator=(Point2D<T>) replaces both operator=(const Point2D<T> &) and
	// operator=(Point2D<T> &&) by using copy and swap idiom.
	template <typename T>
	Point2D<T> &Point2D<T>::operator=(Point2D<T> src)
	{
		this->Swap(src);
		return *this;
	}

	template <typename T>
	Point2D<T>::Point2D(const Coordinate<T, 2> &src) :
		Coordinate<T, 2>(src), x(this->data.at(0)), y(this->data.at(1)) {}

	template <typename T>
	Point2D<T>::Point2D(Coordinate<T, 2> &&src) : Point2D<T>()
	{
		this->data.swap(src.data);
	}

	template <typename T>
	void Point2D<T>::Swap(Point2D<T> &src)
	{
		this->data.swap(src.data);
	}
}

#endif
