#if !defined(COORDINATE1_H)
#define COORDINATE1_H

#include <array>
#include <type_traits>

#include "containers.h"

/*
Defines Point2D<T> class without any base class.
Declares an std::array<T, 2> as a (protected) member.
Defines custom ctor taking std::array<T, 2> as an argument.

Good:
Instantiation is easy using std::array<T, 2>.
Overloaded operators works even outside of the namespace.

Bad:
Needs to overload operators for each class.
*/
namespace Imaging
{
	template <typename T>
	class Point2D
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Point2D(void);
		Point2D(const Point2D<T> &src);
		Point2D(Point2D<T> &&src);
		Point2D &operator=(Point2D<T> src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Point2D(const std::array<T, 2> &srcData);
		Point2D(std::array<T, 2> &&srcData);
		//Point2D &operator=(std::array<T, 2> srcData);

		////////////////////////////////////////////////////////////////////////////////////
		// Overloaded operators.
		Point2D<T> operator+(const Point2D<T> &pt);

		T &x, &y;

	protected:
		void Swap(Point2D<T> &src);
		std::array<T, 2> data_;
	};

	template <typename T>
	class Size2D
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");
	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		Size2D(void);
		Size2D(const Size2D<T> &src);
		Size2D(Size2D<T> &&src);
		Size2D &operator=(Size2D<T> src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		Size2D(const std::array<T, 2> &srcData);
		Size2D(std::array<T, 2> &&srcData);
		//Size2D &operator=(std::array<T, 2> srcData);

		////////////////////////////////////////////////////////////////////////////////////
		// Overloaded operators.
		Size2D<T> operator+(const Size2D<T> &pt);

		T &width, &height;
	};
}

#include "coordinate1_inl.h"

#endif
