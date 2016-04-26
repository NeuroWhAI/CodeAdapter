#include "Transform.h"




BEGIN_NAMESPACE_CA_DRAWING


Transform::Transform()
	: position(0, 0)
	, scale(1, 1)
	, angle(0)
{

}


Transform::~Transform()
{

}

//###########################################################################

void Transform::addTransform(const Transform& other)
{
	position += other.position;

	scale.x *= other.scale.x;
	scale.y *= other.scale.y;

	angle += other.angle;
}


END_NAMESPACE_CA_DRAWING

