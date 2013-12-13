#if !defined(SAFE_OPERATIONS_H)
#define SAFE_OPERATIONS_H

#include <stdexcept>
#include <sstream>
#include <iostream>

#include <safeint.h>

namespace Imaging
{
	template <typename T, typename U>
	std::enable_if_t<std::is_integral<T>::value && std::is_integral<U>::value, void>
		Add(T t, U u, T &result)
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
	std::enable_if_t<std::is_floating_point<T>::value && std::is_arithmetic<U>::value, void>
		Add(T t, U u, T &result)
	{
		result = t + u;
	}

	template <typename T, typename U>
	std::enable_if_t<std::is_integral<T>::value && std::is_floating_point<U>::value, void>
		Add(T t, U u, T &result)
	{
		static_assert(false, "Unsupported scenario.");
	}

	template <typename T, typename U>
	std::enable_if_t<!std::is_arithmetic<T>::value || !std::is_arithmetic<U>::value, void>
		Add(T t, U u, T &result)
	{
		static_assert(false, "Unsupported scenario.");
	}
}

#endif
