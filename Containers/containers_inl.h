#if !defined(CONTAINERS_INL_H)
#define CONTAINERS_INL_H

namespace Imaging
{
	template <typename T, ::size_t N>
	void Add(const std::array<T, N> &a, const std::array<T, N> &b, std::array<T, N> &c)
	{
		auto it_c = c.begin(), it_c_end = c.end();
		for (auto it_a = a.cbegin(), it_b = b.cbegin();
			it_c != it_c_end; ++it_a, ++it_b, ++it_c)
		{
			if (!msl::utilities::SafeAdd(*it_a, *it_b, *it_c))
				throw std::overflow_error(
				"The result of add operation exceeds the limit of the data type.");
		}
	}

	template <typename T, ::size_t N>
	std::array<T, N> operator+(const std::array<T, N> &a, const std::array<T, N> &b)
	{
		std::array<T, N> c;
		Add(a, b, c);
		return c;
	}
}

#endif
