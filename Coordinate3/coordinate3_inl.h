#if !defined(COORDINATE3_INL_H)
#define COORDINATE3_INL_H

namespace Imaging
{
	template <typename T, ::size_t N>
	Coordinate<T, N> Coordinate<T, N>::operator+(const Coordinate<T, N> &other) const
	{
		Coordinate<T, N> result;
		auto it_c = result.data.begin(), it_c_end = result.data.end();
		for (auto it_a = this->data.cbegin(), it_b = other.data.cbegin();
			it_c != it_c_end; ++it_a, ++it_b, ++it_c)
		{
			if (!msl::utilities::SafeAdd(*it_a, *it_b, *it_c))
				throw std::overflow_error(
				"The result of add operation exceeds the limit of the data type.");
		}
		return result;
	}

	template <typename T>
	Point2D<T>::Point2D(void) : x(data.at(0)), y(data.at(1)), Coordinate<T, 2>() {}

	template <typename T>
	Point2D<T>::Point2D(const Point2D<T> &src) :
		x(data.at(0)), y(data.at(1)), Coordinate<T, 2>(src) {}

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
		x(data.at(0)), y(data.at(1)), Coordinate<T, 2>(src) {}

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
