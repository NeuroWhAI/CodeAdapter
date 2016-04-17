#ifndef __CA__RECTANGLE_H__
#define __CA__RECTANGLE_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class RectangleT
{
public:
	RectangleT();
	RectangleT(const T& x, const T& y,
		const T& width, const T& height);
	RectangleT(const PointT<T>& location,
		const SizeT<T>& size);
	virtual ~RectangleT();


public:
	T x, y, width, height;


public:
	void setLocation(const T& x, const T& y);
	void move(const T& deltaX, const T& deltaY);

	void setSize(const T& width, const T& height);
	void addSize(const T& deltaWidth, const T& deltaHeight);


public:
	virtual bool containsPoint(const T& x, const T& y) const;
	virtual bool containsPoint(const PointT<T>& point) const; 
};


using Rectangle = RectangleT<i32>;
using RectangleF = RectangleT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Rectangle.inl"


#endif