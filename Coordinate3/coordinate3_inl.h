#if !defined(COORDINATE3_INL_H)
#define COORDINATE3_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Coordinate<T, N>

	template <typename T, ::size_t N> template <typename U>
	Coordinate<T, N> Coordinate<T, N>::operator+(const Coordinate<U, N> &rhs) const
	{
		Coordinate<T, N> result;
		AddRange(this->data.cbegin(), this->data.cend(), rhs.data.cbegin(),
			result.data.begin());
		return result;
	}

	template <typename T, ::size_t N> template <typename U>
	Coordinate<T, N> Coordinate<T, N>::operator+(U rhs) const
	{
		Coordinate<T, N> result;
		auto it = this->data.cbegin(), itEnd = this->data.cend();
		for (auto itDst = result.data.begin(); it != itEnd; ++it, ++itDst)
			Add(*it, rhs, *itDst);
		return result;
	}

	template <typename T, ::size_t N> template <typename U>
	void Coordinate<T, N>::operator+=(const Coordinate<U, N> &rhs)
	{
		AddRange(this->data.begin(), this->data.end(), rhs.data.cbegin());
	}

	template <typename T, ::size_t N> template <typename U>
	void Coordinate<T, N>::operator+=(U rhs)
	{
		for (auto it = this->data.begin(), itEnd = this->data.end(); it != itEnd; ++it)
			Add(*it, rhs, *it);
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
