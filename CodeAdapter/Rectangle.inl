#include "Rectangle.h"

#include "Point.h"
#include "Size.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
RectangleT<T>::RectangleT()
	: x(T())
	, y(T())
	, width(T())
	, height(T())
{

}


template <typename T>
RectangleT<T>::RectangleT(const T& x, const T& y,
	const T& width, const T& height)
	: x(x)
	, y(y)
	, width(width)
	, height(height)
{

}


template <typename T>
RectangleT<T>::RectangleT(const PointT<T>& location,
	const SizeT<T>& size)
	: x(location.x)
	, y(location.y)
	, width(size.width)
	, height(size.height)
{

}


template <typename T>
RectangleT<T>::~RectangleT()
{

}

//###########################################################################

template <typename T>
void RectangleT<T>::setLocation(const T& x, const T& y)
{
	this->x = x;
	this->y = y;
}


template <typename T>
void RectangleT<T>::move(const T& deltaX, const T& deltaY)
{
	x += deltaX;
	y += deltaY;
}

//--------------------------------------------------------------------------

template <typename T>
void RectangleT<T>::setSize(const T& width, const T& height)
{
	this->width = width;
	this->height = height;
}


template <typename T>
void RectangleT<T>::addSize(const T& deltaWidth, const T& deltaHeight)
{
	width += deltaWidth;
	height += deltaHeight;
}

//###########################################################################

template <typename T>
bool RectangleT<T>::containsPoint(const T& x, const T& y) const
{
	return ((x >= this->x) && (x < this->x + width)
		&& (y >= this->y) && (y < this->y + height));
}


template <typename T>
bool RectangleT<T>::containsPoint(const PointT<T>& point) const
{
	return containsPoint(point.x, point.y);
}


END_NAMESPACE_CA_DRAWING

