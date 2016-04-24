#ifndef __CA__TRANSFORM_H__
#define __CA__TRANSFORM_H__


#include "BasicDeclaration.h"

#include "Point.h"
#include "Vector.h"
#include "Angle.h"




BEGIN_NAMESPACE_CA_DRAWING


class Transform
{
public:
	Transform();
	virtual ~Transform();


public:
	PointF position;
	VectorF scale;
	Utility::Angle angle;


public:
	void addTransform(const Transform& other);
};


END_NAMESPACE_CA_DRAWING


#endif