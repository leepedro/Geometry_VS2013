#if !defined(COORDINATES2_H)
#define COORDINATES2_H

#include <array>

namespace Imaging
{
	template <typename T>
	class Data2D
	{
	public:
		Data2D(void);
		Data2D(const Data2D<T> &src);
		Data2D(Data2D<T> &&src);
		Data2D &operator=(Data2D<T> src);

		Data2D(const std::array<T, 2> &srcData);
		Data2D(std::array<T, 2> &&srcData);

	protected:
		void Swap(Data2D<T> &src);
		std::array<T, 2> data_;
	};

	template <typename T>
	class Point2DNew : public Data2D<T>
	{
	public:
		Point2DNew(void);
		Point2DNew(const Point2DNew<T> &src);
		Point2DNew(Point2DNew<T> &&src);
		Point2DNew &operator=(Point2DNew<T> src);

		//Point2D()

		T &x, &y;
	};

}

#include "coordinates2_inl.h"

#endif
