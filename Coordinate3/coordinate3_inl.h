#if !defined(COORDINATE3_INL_H)
#define COORDINATE3_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Array<T, N>

	template <typename T, ::size_t N> template <typename U>
	Array<T, N> Array<T, N>::operator+(const Array<U, N> &rhs) const
	{
		Array<T, N> result;
		AddRange(this->data.cbegin(), this->data.cend(), rhs.data.cbegin(),
			result.data.begin());
		return result;
	}

	// NOTE: This function template is extremely tricky to implement.
	// Must check if typename U is simple arithmetic, otherwise even Array<T, N> will be
	// taken as U instead of the more specified type.
	template <typename T, ::size_t N> template <typename U>
	std::enable_if_t<std::is_arithmetic<U>::value, Array<T, N>>
		Array<T, N>::operator+(U rhs) const
	{
		Array<T, N> result;
		auto it = this->data.cbegin(), itEnd = this->data.cend();
		for (auto itDst = result.data.begin(); it != itEnd; ++it, ++itDst)
			Add(*it, rhs, *itDst);
		return result;
	}

	template <typename T, ::size_t N> template <typename U>
	void Array<T, N>::operator+=(const Array<U, N> &rhs)
	{
		AddRange(this->data.begin(), this->data.end(), rhs.data.cbegin());
	}

	// Again, type checking is mandatory for this function.
	template <typename T, ::size_t N> template <typename U>
	std::enable_if_t<std::is_arithmetic<U>::value, void> Array<T, N>::operator+=(U rhs)
	{
		for (auto it = this->data.begin(), itEnd = this->data.end(); it != itEnd; ++it)
			Add(*it, rhs, *it);
	}

	////////////////////////////////////////////////////////////////////////////////////
	// Point2D<T>

	template <typename T>
	Point2D<T>::Point2D(void) :
		Array<T, 2>(), x(this->data.at(0)), y(this->data.at(1)) {}

	template <typename T>
	Point2D<T>::Point2D(const Point2D<T> &src) :
		Array<T, 2>(src), x(this->data.at(0)), y(this->data.at(1)) {}

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
	Point2D<T>::Point2D(const Array<T, 2> &src) :
		Array<T, 2>(src), x(this->data.at(0)), y(this->data.at(1)) {}

	template <typename T>
	Point2D<T>::Point2D(Array<T, 2> &&src) : Point2D<T>()
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
