#if !defined(ALGORITHMS_H)
#define ALGORITHMS_H

#include "safe_operations.h"

namespace Imaging
{

	template <typename T_ConstIterator, typename T_Iterator>
	void Add(T_ConstIterator it_a, T_ConstIterator it_a_last, T_ConstIterator it_b,
		T_Iterator it_c)
	{
		for (; it_a != it_a_last; ++it_a, ++it_b, ++it_c)
		{
			Add(*it_a, *it_b, *it_c);
			//if (!msl::utilities::SafeAdd(*it_a, *it_b, *it_c))
			//	throw std::overflow_error(
			//	"The result of add operation exceeds the limit of the data type.");
		}

	}
}

#endif
