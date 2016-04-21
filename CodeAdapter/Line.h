#ifndef __CA__LINE_H__
#define __CA__LINE_H__


#include "BasicDeclaration.h"

#include "Point.h"




BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class LineT
{
public:
	LineT();
	LineT(const PointT<T>& begin, const PointT<T>& end);
	LineT(const T& beginX, const T& beginY,
		const T& endX, const T& endY);
	virtual ~LineT();


public:
	PointT<T> begin, end;


public:
	const T getLengthSq() const;
	const T getLength() const;
	const PointT<T> getMiddle() const;
};


using Line = LineT<i32>;
using LineF = LineT<f32>;


END_NAMESPACE_CA_DRAWING


#include "Line.inl"


#endif