#if !defined(SAFE_OPERATIONS_H)
#define SAFE_OPERATIONS_H

#include <stdexcept>
#include <sstream>
#include <safeint.h>

namespace Imaging
{
	template <typename T>
	std::enable_if_t<std::is_integral<T>::value, void> Add(T a, T b, T &c)
	{
		if (!msl::utilities::SafeAdd(a, b, c))
		{
			std::ostringstream errMsg;
			errMsg << "The result of add operation exceeds the limit of " <<
				typeid(c).name() << " data type.";
			throw std::overflow_error(errMsg.str());
		}
	}

	template <typename T>
	std::enable_if_t<std::is_floating_point<T>::value, void> Add(T a, T b, T &c)
	{
		c = a + b;
	}
}

#endif
