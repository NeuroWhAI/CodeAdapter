#include "Line.h"

#include <cmath>




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
LineT<T>::LineT()
{

}


template <typename T>
LineT<T>::LineT(const PointT<T>& begin, const PointT<T>& end)
	: begin(begin)
	, end(end)
{

}


template <typename T>
LineT<T>::LineT(const T& beginX, const T& beginY,
	const T& endX, const T& endY)
	: begin(beginX, beginY)
	, end(endX, endY)
{

}


template <typename T>
LineT<T>::~LineT()
{

}

//###########################################################################

template <typename T>
const T LineT<T>::getLengthSq() const
{
	T subX = begin.x - end.x;
	T subY = begin.y - end.y;

	return ((subX * subX) + (subY * subY));
}


template <typename T>
const T LineT<T>::getLength() const
{
	return std::sqrt<T>(getLengthSq());
}


template <typename T>
const PointT<T> LineT<T>::getMiddle() const
{
	return PointT<T>((begin.x + end.x) / T(2), (begin.y + end.y) / T(2));
}


END_NAMESPACE_CA_DRAWING

