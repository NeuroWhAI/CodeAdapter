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

//###########################################################################

PointF Transform::inverseTransformPoint(const PointF& point) const
{
	PointF inversePoint = point;

	inversePoint -= position;

	Utility::Angle pointAngle = std::atan2(inversePoint.y, inversePoint.x) * (180.0f / 3.14159265358979323846f);
	f32 angleGap = static_cast<f32>(pointAngle) - angle;
	angleGap *= (3.14159265358979323846f / 180.0f);
	VectorF pointVector = { inversePoint.x, inversePoint.y };
	f32 vecLength = pointVector.getLength();
	inversePoint.x = std::cosf(angleGap) * vecLength;
	inversePoint.y = std::sinf(angleGap) * vecLength;

	inversePoint.x /= scale.x;
	inversePoint.y /= scale.y;


	return inversePoint;
}


END_NAMESPACE_CA_DRAWING

