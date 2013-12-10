namespace Imaging
{
	template <typename T>
	Data2D<T>::Data2D(void) {}

	template <typename T>
	Data2D<T>::Data2D(const Data2D<T> &src) : data_(src.data_) {}

	template <typename T>
	Data2D<T>::Data2D(Data2D<T> &&src)
	{
		this->Swap(src);
	}

	// This operator=(Point2D<T>) replaces both operator=(const Point2D<T> &) and
	// operator=(Point2D<T> &&) by using copy and swap idiom.
	template <typename T>
	Data2D<T> &Data2D<T>::operator=(Data2D<T> src)
	{
		this->Swap(src);
		return *this;
	}

	template <typename T>
	Data2D<T>::Data2D(const std::array<T, 2> &srcData) : data_(srcData) {}

	template <typename T>
	Data2D<T>::Data2D(std::array<T, 2> &&srcData)
	{
		this->data_.swap(srcData);
	}

	template <typename T>
	void Data2D<T>::Swap(Data2D<T> &src)
	{
		this->data_.swap(src.data_);
	}

	// Even though this ctor does not explicitly take any action on data_,
	// it initializes all members.
	// If you want to initialize any member in a different way, you should not call
	// this ctor as a delegation ctor.
	template <typename T>
	Point2DNew<T>::Point2DNew(void) : x(data_.at(0)), y(data_.at(1)) {}

	template <typename T>
	Point2DNew<T>::Point2DNew(const Point2DNew<T> &src) :
		x(data_.at(0)), y(data_.at(1)), data_(src.data_) {}

	template <typename T>
	Point2DNew<T>::Point2DNew(Point2DNew<T> &&src) : Point2DNew<T>()
	{
		this->Swap(src);
	}

	// This operator=(Point2D<T>) replaces both operator=(const Point2D<T> &) and
	// operator=(Point2D<T> &&) by using copy and swap idiom.
	template <typename T>
	Point2DNew<T> &Point2DNew<T>::operator=(Point2DNew<T> src)
	{
		Data2D::operator=(src);
		//this->Swap(src);
		return *this;
	}

}