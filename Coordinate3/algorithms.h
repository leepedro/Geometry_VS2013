#if !defined(ALGORITHMS_H)
#define ALGORITHMS_H

#include "safe_operations.h"

namespace Imaging
{
	// C = A + B
	template <typename InputIterator, typename OutputIterator>
	void AddRange(InputIterator it_a, InputIterator it_a_last, InputIterator it_b,
		OutputIterator it_c)
	{
		for (; it_a != it_a_last; ++it_a, ++it_b, ++it_c)
			Add(*it_a, *it_b, *it_c);
	}

	// A += B
	template <typename InputIterator, typename OutputIterator>
	void AddRange(OutputIterator it_a, OutputIterator it_a_last, InputIterator it_b)
	{
		for (; it_a != it_a_last; ++it_a, ++it_b)
			Add(*it_a, *it_b, *it_a);
	}
}

#endif
