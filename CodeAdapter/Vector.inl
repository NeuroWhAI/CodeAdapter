#include "Vector.h"

#include <cmath>
#include <limits>




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
const VectorT<T> VectorT<T>::Zero = { T(0), T(0) };

//###########################################################################

template <typename T>
VectorT<T>::VectorT()
	: x(T())
	, y(T())
{

}


template <typename T>
VectorT<T>::VectorT(const T& x, const T& y)
	: x(x)
	, y(y)
{

}


template <typename T>
VectorT<T>::~VectorT()
{

}

//###########################################################################

template <typename T>
void VectorT<T>::setVector(const T& x, const T& y)
{
	this->x = x;
	this->y = y;
}


template <typename T>
void VectorT<T>::addVector(const T& deltaX, const T& deltaY)
{
	x += deltaX;
	y += deltaY;
}


template <typename T>
void VectorT<T>::normalize(const T& length)
{
	normalize(length, Identity<T>());
}

//###########################################################################

template <typename T>
const T VectorT<T>::getLength() const
{
	return std::sqrt((x * x) + (y * y));
}


template <typename T>
const T VectorT<T>::getLengthSq() const
{
	return ((x * x) + (y * y));
}

//###########################################################################

template <typename T>
const T VectorT<T>::dotProduct(const VectorT<T>& right) const
{
	return (x * right.x + y * right.y);
}

//###########################################################################

template <typename T>
template <typename T2>
VectorT<T>::operator VectorT<T2>() const
{
	return VectorT<T2>(static_cast<T2>(x), static_cast<T2>(y));
}


template <typename T>
VectorT<T> VectorT<T>::operator+ () const
{
	return *this;
}


template <typename T>
VectorT<T> VectorT<T>::operator- () const
{
	return VectorT<T>(-x, -y);
}


template <typename T>
VectorT<T> VectorT<T>::operator+ (const VectorT<T>& right) const
{
	return VectorT<T>(x + right.x, y + right.y);
}


template <typename T>
VectorT<T>& VectorT<T>::operator+= (const VectorT<T>& right)
{
	addVector(right.x, right.y);
	return *this;
}


template <typename T>
VectorT<T> VectorT<T>::operator- (const VectorT<T>& right) const
{
	return VectorT<T>(x - right.x, y - right.y);
}


template <typename T>
VectorT<T>& VectorT<T>::operator-= (const VectorT<T>& right)
{
	addVector(-right.x, -right.y);
	return *this;
}


template <typename T>
VectorT<T> VectorT<T>::operator* (const T& right) const
{
	return VectorT<T>(x * right, y * right);
}


template <typename T>
VectorT<T>& VectorT<T>::operator*= (const T& right)
{
	x *= right;
	y *= right;
	return *this;
}


template <typename T>
VectorT<T> VectorT<T>::operator/ (const T& right) const
{
	return VectorT<T>(x / right, y / right);
}


template <typename T>
VectorT<T>& VectorT<T>::operator/= (const T& right)
{
	x /= right;
	y /= right;
	return *this;
}


template <typename T>
bool VectorT<T>::operator== (const VectorT<T>& right) const
{
	return equals(right, Identity<T>());
}


template <typename T>
bool VectorT<T>::operator!= (const VectorT<T>& right) const
{
	return !this->operator==(right);
}

//###########################################################################

template <typename T>
template <typename ARG_TYPE>
void VectorT<T>::normalize(const T& length, Identity<ARG_TYPE>)
{
	const T vLen = getLength();

	if (vLen != 0)
	{
		x /= vLen;
		y /= vLen;

		x *= length;
		y *= length;
	}
}


template <typename T>
void VectorT<T>::normalize(const T& length, Identity<f32>)
{
	const f32 vLen = getLength();

	if (std::abs(vLen) > std::numeric_limits<f32>::epsilon())
	{
		x /= vLen;
		y /= vLen;

		x *= length;
		y *= length;
	}
	else
	{
		x = 0.0f;
		y = 0.0f;
	}
}

//--------------------------------------------------------------------------

template <typename T>
template <typename ARG_TYPE>
bool VectorT<T>::equals(const VectorT<T>& right, Identity<ARG_TYPE>) const
{
	return ((x == right.x) && (x == right.y));
}


template <typename T>
bool VectorT<T>::equals(const VectorT<T>& right, Identity<f32>) const
{
	const float epsilon = std::numeric_limits<T>::epsilon();
	return (abs(x - right.x) < epsilon
		&& abs(y - right.y) < epsilon);
}


END_NAMESPACE_CA_DRAWING


template <typename T>
CodeAdapter::Drawing::VectorT<T> operator* (const T& left,
	const CodeAdapter::Drawing::VectorT<T>& right)
{
	return CodeAdapter::Drawing::VectorT<T>(left * right.x,
		left * right.y);
}

