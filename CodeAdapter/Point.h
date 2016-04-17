#ifndef __CA__POINT_H__
#define __CA__POINT_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class PointT
{
public:
	static const PointT<T> Zero;


public:
	PointT();
	PointT(const T& x, const T& y);
	virtual ~PointT();


public:
	T x, y;


public:
	void setLocation(const T& x, const T& y);
	void move(const T& deltaX, const T& deltaY);


public:
	PointT<T> operator+ (const PointT<T>& right) const;
	PointT<T>& operator+= (const PointT<T>& right);
	PointT<T> operator- (const PointT<T>& right) const;
	PointT<T>& operator-= (const PointT<T>& right);
	PointT<T> operator* (const T& right) const;
	PointT<T>& operator*= (const T& right);
	PointT<T> operator/ (const T& right) const;
	PointT<T>& operator/= (const T& right);
	bool operator== (const PointT<T>& right) const;
	bool operator!= (const PointT<T>& right) const;


private:
	template <typename ID_TYPE>
	struct Identity { };

	template <typename ARG_TYPE>
	bool equals(const PointT<T>& right, Identity<ARG_TYPE>) const;
	bool equals(const PointT<T>& right, Identity<f32>) const;
};


using Point = PointT<i32>;
using PointF = PointT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Point.inl"


#endif