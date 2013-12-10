namespace Imaging
{
	// Even though this ctor does not explicitly take any action on data_,
	// it initializes all members.
	// If you want to initialize any member in a different way, you should not call
	// this ctor as a delegation ctor.
	template <typename T>
	Point2D<T>::Point2D(void) : x(data_.at(0)), y(data_.at(1)) {}	

	template <typename T>
	Point2D<T>::Point2D(const Point2D<T> &src) :
		x(data_.at(0)), y(data_.at(1)), data_(src.data_) {}

	template <typename T>
	Point2D<T>::Point2D(Point2D<T> &&src) : Point2D<T>()
	{
		this->Swap(src);
	}

	// This operator=(Point2D<T>) replaces both operator=(const Point2D<T> &) and
	// operator=(Point2D<T> &&) by using copy and swap idiom.
	template <typename T>
	Point2D<T> &Point2D<T>::operator=(Point2D<T> src)
	{
		this->Swap(src);
		return *this;
	}

	template <typename T>
	Point2D<T>::Point2D(const std::array<T, 2> &srcData) :
		x(data_.at(0)), y(data_.at(1)), data_(srcData) {}

	template <typename T>
	Point2D<T>::Point2D(std::array<T, 2> &&srcData) : Point2D<T>()
	{
		this->data_.swap(srcData);
	}

	//template <typename T>
	//Point2D<T> &Point2D<T>::operator=(std::array<T, 2> src)
	//{
	//	this->data_.swap(srcData);
	//	return *this;
	//}

	template <typename T>
	void Point2D<T>::Swap(Point2D<T> &src)
	{
		this->data_.swap(src.data_);
	}
}