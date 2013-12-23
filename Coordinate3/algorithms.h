#if !defined(ALGORITHMS_H)
#define ALGORITHMS_H

#include "safe_operations.h"

namespace Imaging
{
	// C = A + B
	template <typename InputIteratorA, typename InputIteratorB, typename OutputIterator>
	void AddRange(InputIteratorA itA, InputIteratorA itA_last, InputIteratorB itB,
		OutputIterator itC)
	{
		for (; itA != itA_last; ++itA, ++itB, ++itC)
			Add(*itA, *itB, *itC);
	}

	// B += A
	template <typename InputIterator, typename InOutputIterator>
	void AddRange(InputIterator itA, InputIterator itA_last, InOutputIterator itB)
	{
		for (; itA != itA_last; ++itA, ++itB)
			Add(*itB, *itA, *itB);
	}

	// ++A
	template <typename Iterator>
	void IncrementRange(Iterator it, Iterator itLast)
	{
		for (; it != itLast; ++it)
			Increment(*it);
	}
}

#endif
