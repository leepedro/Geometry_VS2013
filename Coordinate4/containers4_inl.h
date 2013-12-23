#if !defined(CONTAINERS4_INL_H)
#define CONTAINERS4_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Array<T, N>

	template <typename T, ::size_t N> template <typename U>
	Array<T, N> Array<T, N>::operator+(const Array<U, N> &rhs) const
	{
		std::cout << "Array<T, N> Array<T, N>::operator+(const Array<U, N> &) const" << std::endl;
		Array<T, N> result;
		AddRange(this->cbegin(), this->cend(), rhs.cbegin(), result.begin());
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
		std::cout << "Array<T, N> Array<T, N>::operator+(U) const" << std::endl;
		Array<T, N> result;
		auto it = this->cbegin(), itEnd = this->cend();
		for (auto itDst = result.begin(); it != itEnd; ++it, ++itDst)
			Add(*it, rhs, *itDst);
		return result;
	}

	template <typename T, ::size_t N> template <typename U>
	void Array<T, N>::operator+=(const Array<U, N> &rhs)
	{
		std::cout << "void Array<T, N>::operator+=(const Array<U, N> &)" << std::endl;
		AddRange(rhs.cbegin(), rhs.cend(), this->begin());
	}

	// Again, type checking is mandatory for this function.
	template <typename T, ::size_t N> template <typename U>
	std::enable_if_t<std::is_arithmetic<U>::value, void> Array<T, N>::operator+=(U rhs)
	{
		std::cout << "void Array<T, N>::operator+=(U)" << std::endl;
		for (auto it = this->begin(), itEnd = this->end(); it != itEnd; ++it)
			Add(*it, rhs, *it);
	}

	template <typename T, ::size_t N>
	Array<T, N> &Array<T, N>::operator++(void)
	{
		std::cout << "Array<T, N> &Array<T, N>::operator++(void)" << std::endl;
		IncrementRange(this->begin(), this->end());
		return *this;
	}

	template <typename T, ::size_t N>
	Array<T, N> Array<T, N>::operator++(int)
	{
		std::cout << "Array<T, N> Array<T, N>::operator++(int)" << std::endl;
		Array<T, N> temp = *this;
		++*this;
		return temp;
	}

	// Array<T, N>
	////////////////////////////////////////////////////////////////////////////////////


	template <typename T, std::size_t N>
	void TakeArray(const Array<T, N> &src)
	{
		std::cout << "TakeArray(const Array<T, N> &)" << std::endl;
	}
}

#endif
