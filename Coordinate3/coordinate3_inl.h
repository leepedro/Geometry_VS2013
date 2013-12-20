#if !defined(COORDINATE3_INL_H)
#define COORDINATE3_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Array<T, N>

	/*
	std::array<T, N> cannot be used with std::initialization_list<T>.
	*/
	//template <typename T, ::size_t N>
	//Array<T, N>::Array(const std::initializer_list<T> &srcList) : data(srcList) {}

	template <typename T, ::size_t N> template <typename U>
	Array<T, N> Array<T, N>::operator+(const Array<U, N> &rhs) const
	{
		std::cout << "Array<T, N> Array<T, N>::operator+(const Array<U, N> &) const" << std::endl;
		Array<T, N> result;
		AddRange(this->data.cbegin(), this->data.cend(), rhs.data.cbegin(),
			result.data.begin());
		return result;
	}

	/* WARNING:
	This function template is extremely tricky to implement.
	Must check if typename U is simple arithmetic type, otherwise even Array<T, N> will be
	taken as U instead of a more specified type.
	*/
	template <typename T, ::size_t N> template <typename U>
	std::enable_if_t<std::is_arithmetic<U>::value, Array<T, N>>
		Array<T, N>::operator+(U rhs) const
	{
		std::cout << "std::enable_if_t<std::is_arithmetic<U>::value, Array<T, N>> Array<T, N>::operator+(U) const" << std::endl;
		Array<T, N> result;
		auto it = this->data.cbegin(), itEnd = this->data.cend();
		for (auto itDst = result.data.begin(); it != itEnd; ++it, ++itDst)
			Add(*it, rhs, *itDst);
		return result;
	}

	template <typename T, ::size_t N> template <typename U>
	void Array<T, N>::operator+=(const Array<U, N> &rhs)
	{
		std::cout << "void Array<T, N>::operator+=(const Array<U, N> &)" << std::endl;
		AddRange(rhs.data.cbegin(), rhs.data.cend(), this->data.begin());
	}

	// Again, type checking is mandatory for this function.
	template <typename T, ::size_t N> template <typename U>
	std::enable_if_t<std::is_arithmetic<U>::value, void> Array<T, N>::operator+=(U rhs)
	{
		std::cout << "std::enable_if_t<std::is_arithmetic<U>::value, void> Array<T, N>::operator+=(U)" << std::endl;
		for (auto it = this->data.begin(), itEnd = this->data.end(); it != itEnd; ++it)
			Add(*it, rhs, *it);
	}

	////////////////////////////////////////////////////////////////////////////////////
	// Point2D<T>

	template <typename T>
	Point2D<T>::Point2D(void) :	Array<T, 2>()
	{
		std::cout << "Point2D<T>::Point2D(void)" << std::endl;
	}

	template <typename T>
	Point2D<T>::Point2D(const Point2D<T> &src) : Array<T, 2>(src)
	{
		std::cout << "Point2D<T>::Point2D(const Point2D<T> &)" << std::endl;
	}

	template <typename T>
	Point2D<T> &Point2D<T>::operator=(const Point2D<T> &src)
	{
		std::cout << "Point2D<T> &Point2D<T>::operator=(const Point2D<T> &)" << std::endl;
		this->data = src.data;
		return *this;
	}

	template <typename T>
	Point2D<T>::Point2D(const Array<T, 2> &srcData) : Array<T, 2>(srcData)
	{
		std::cout << "Point2D<T>::Point2D(const Array<T, 2> &)" << std::endl;
	}

	//template <typename T>
	//Point2D<T>::Point2D(T x, T y) : Point2D<T>()
	//{
	//	std::cout << "Point2D<T>::Point2D(T x, T y)" << std::endl;
	//	this->x = x;
	//	this->y = y;
	//}

	template <typename T>
	Point2D<T>::Point2D(const std::initializer_list<T> &srcList) : Point2D<T>()
	{
		std::cout << "Point2D<T>::Point2D(const std::initializer_list<T> &srcList)" << std::endl;
		auto it = srcList.begin();
		this->x = *it;
		this->y = *(it + 1);
	}


	template <typename T>
	Point2D<T> FuncA(const Point2D<T> &src1, Point2D<T> src2)
	{
		//Point2D<T> temp1 = std::move(temp);
		Point2D<T> temp1 = src1;
		temp1 += src2;
		//return temp1;
		return { 1, 2 };
	}

}

#endif
