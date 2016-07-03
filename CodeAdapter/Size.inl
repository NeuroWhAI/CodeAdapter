#include "Size.h"

#include <cmath>
#include <limits>




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
const SizeT<T> SizeT<T>::Zero = { T(0), T(0) };

//###########################################################################

template <typename T>
SizeT<T>::SizeT()
	: width(T())
	, height(T())
{

}


template <typename T>
SizeT<T>::SizeT(const T& width, const T& height)
	: width(width)
	, height(height)
{

}


template <typename T>
SizeT<T>::~SizeT()
{

}

//###########################################################################

template <typename T>
void SizeT<T>::setSize(const T& width, const T& height)
{
	this->width = width;
	this->height = height;
}


template <typename T>
void SizeT<T>::addSize(const T& deltaWidth, const T& deltaHeight)
{
	this->width += deltaWidth;
	this->height += deltaHeight;
}

//###########################################################################

template <typename T>
template <typename T2>
SizeT<T>::operator SizeT<T2>() const
{
	return SizeT<T2>(static_cast<T2>(width), static_cast<T2>(height));
}


template <typename T>
SizeT<T> SizeT<T>::operator+ (const SizeT<T>& right) const
{
	return SizeT<T>(width + right.width, height + right.height);
}


template <typename T>
SizeT<T>& SizeT<T>::operator+= (const SizeT<T>& right)
{
	addSize(right.width, right.height);
	return *this;
}


template <typename T>
SizeT<T> SizeT<T>::operator- (const SizeT<T>& right) const
{
	return SizeT<T>(width - right.width, height - right.height);
}


template <typename T>
SizeT<T>& SizeT<T>::operator-= (const SizeT<T>& right)
{
	addSize(-right.width, -right.height);
	return *this;
}


template <typename T>
SizeT<T> SizeT<T>::operator* (const T& right) const
{
	return SizeT<T>(width * right, height * right);
}


template <typename T>
SizeT<T>& SizeT<T>::operator*= (const T& right)
{
	width *= right;
	height *= right;
	return *this;
}


template <typename T>
SizeT<T> SizeT<T>::operator/ (const T& right) const
{
	return SizeT<T>(width / right, height / right);
}


template <typename T>
SizeT<T>& SizeT<T>::operator/= (const T& right)
{
	width /= right;
	height /= right;
	return *this;
}


template <typename T>
bool SizeT<T>::operator== (const SizeT<T>& right) const
{
	return equals(right, Identity<T>());
}


template <typename T>
bool SizeT<T>::operator!= (const SizeT<T>& right) const
{
	return !this->operator==(right);
}

//###########################################################################

template <typename T>
template <typename ARG_TYPE>
bool SizeT<T>::equals(const SizeT<T>& right, Identity<ARG_TYPE>) const
{
	return ((width == right.width) && (height == right.height));
}


template <typename T>
bool SizeT<T>::equals(const SizeT<T>& right, Identity<f32>) const
{
	const float epsilon = std::numeric_limits<T>::epsilon();
	return (abs(width - right.width) < epsilon
		&& abs(height - right.height) < epsilon);
}


END_NAMESPACE_CA_DRAWING


template <typename T>
CodeAdapter::Drawing::SizeT<T> operator* (const T& left,
	const CodeAdapter::Drawing::SizeT<T>& right)
{
	return CodeAdapter::Drawing::SizeT<T>(left * right.x,
		left * right.y);
}

