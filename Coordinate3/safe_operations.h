#if !defined(SAFE_OPERATIONS_H)
#define SAFE_OPERATIONS_H

#include <stdexcept>
#include <sstream>
#include <iostream>

#include <safeint.h>

namespace Imaging
{
	template <typename T, typename U>
	std::enable_if_t<std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, void>
	Add(T t, U u, T &result)
	{
		AddImp(t, u, result, std::is_integral<T>(), std::is_integral<U>());
	}

	template <typename T, typename U>
	void AddImp(T t, U u, T &result, std::true_type, std::true_type)
	{
		if (!msl::utilities::SafeAdd(t, u, result))
		{
			std::ostringstream errMsg;
			errMsg << "The result of add operation exceeds the limit of " <<
				typeid(result).name() << " data type.";
			throw std::overflow_error(errMsg.str());
		}
	}

	template <typename T, typename U>
	void AddImp(T t, U u, T &result, std::true_type, std::false_type)
	{
		static_assert(false, "Unsupported scenario.");
	}

	template <typename T, typename U>
	void AddImp(T t, U u, T &result, std::false_type, std::true_type)
	{
		result = t + u;
	}

	template <typename T, typename U>
	void AddImp(T t, U u, T &result, std::false_type, std::false_type)
	{
		result = t + u;
	}

	template <typename T, typename U>
	std::enable_if_t<std::is_arithmetic<T>::value && std::is_arithmetic<U>::value, void>
	Subtract(T t, U u, T &result)
	{
		SubtractImp(t, u, result, std::is_integral<T>(), std::is_integral<U>());
	}

	template <typename T, typename U>
	void SubtractImp(T t, U u, T &result, std::true_type, std::true_type)
	{
		if (!msl::utilities::SafeSubtract(t, u, result))
		{
			std::ostringstream errMsg;
			errMsg << "The result of add operation exceeds the limit of " <<
				typeid(result).name() << " data type.";
			throw std::overflow_error(errMsg.str());
		}
	}

	template <typename T, typename U>
	void SubtractImp(T t, U u, T &result, std::true_type, std::false_type)
	{
		static_assert(false, "Unsupported scenario.");
	}

	template <typename T, typename U>
	void SubtractImp(T t, U u, T &result, std::false_type, std::true_type)
	{
		result = t - u;
	}

	template <typename T, typename U>
	void SubtractImp(T t, U u, T &result, std::false_type, std::false_type)
	{
		result = t - u;
	}
}

#endif
