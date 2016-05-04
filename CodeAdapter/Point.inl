#include "Point.h"

#include <cmath>
#include <limits>




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
const PointT<T> PointT<T>::Zero = { T(0), T(0) };

//###################################################################

template <typename T>
PointT<T>::PointT()
	: x(T())
	, y(T())
{

}


template <typename T>
PointT<T>::PointT(const T& x, const T& y)
	: x(x)
	, y(y)
{

}


template <typename T>
PointT<T>::~PointT()
{

}

//###################################################################

template <typename T>
void PointT<T>::setLocation(const T& x, const T& y)
{
	this->x = x;
	this->y = y;
}


template <typename T>
void PointT<T>::move(const T& deltaX, const T& deltaY)
{
	x += deltaX;
	y += deltaY;
}

//###################################################################

template <typename T>
template <typename T2>
PointT<T>::operator PointT<T2>() const
{
	return PointT<T2>(static_cast<T2>(x), static_cast<T2>(y));
}


template <typename T>
PointT<T> PointT<T>::operator+ (const PointT<T>& right) const
{
	return PointT<T>(x + right.x, y + right.y);
}


template <typename T>
PointT<T>& PointT<T>::operator+= (const PointT<T>& right)
{
	move(right.x, right.y);
	return *this;
}


template <typename T>
PointT<T> PointT<T>::operator- (const PointT<T>& right) const
{
	return PointT<T>(x - right.x, y - right.y);
}


template <typename T>
PointT<T>& PointT<T>::operator-= (const PointT<T>& right)
{
	move(-right.x, -right.y);
	return *this;
}


template <typename T>
PointT<T> PointT<T>::operator* (const T& right) const
{
	return PointT<T>(x * right, y * right);
}


template <typename T>
PointT<T>& PointT<T>::operator*= (const T& right)
{
	x *= right;
	y *= right;
	return *this;
}


template <typename T>
PointT<T> PointT<T>::operator/ (const T& right) const
{
	return PointT<T>(x / right, y / right);
}


template <typename T>
PointT<T>& PointT<T>::operator/= (const T& right)
{
	x /= right;
	y /= right;
	return *this;
}


template <typename T>
bool PointT<T>::operator== (const PointT<T>& right) const
{
	return ((x == right.x) && (y == right.y));
}


template <typename T>
bool PointT<T>::operator!= (const PointT<T>& right) const
{
	return !this->operator==(right);
}

//###########################################################################

template <typename T>
template <typename ARG_TYPE>
bool PointT<T>::equals(const PointT<T>& right, Identity<ARG_TYPE>) const
{
	return ((x == right.x) && (x == right.y));
}


template <typename T>
bool PointT<T>::equals(const PointT<T>& right, Identity<f32>) const
{
	const float epsilon = std::numeric_limits<T>::epsilon();
	return (abs(x - right.x) < epsilon
		&& abs(y - right.y) < epsilon);
}


END_NAMESPACE_CA_DRAWING


template <typename T>
CodeAdapter::Drawing::PointT<T> operator* (const T& left,
	const CodeAdapter::Drawing::PointT<T>& right)
{
	return CodeAdapter::Drawing::PointT<T>(left * right.x,
		left * right.y);
}

