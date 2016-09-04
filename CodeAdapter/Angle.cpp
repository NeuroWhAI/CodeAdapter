#include "Angle.h"

#include <cmath>




BEGIN_NAMESPACE_CA_UTILITY


Angle::Angle()
	: m_angle(0.0f)
{

}


Angle::Angle(const Angle& angle)
	: m_angle(angle.m_angle)
{

}


Angle::Angle(Angle&& angle)
	: m_angle(angle.m_angle)
{

}


Angle::Angle(f32 angle)
	: m_angle(angle)
{
	filterAngle();
}


Angle::~Angle()
{

}

//###########################################################################

void Angle::setAngle(f32 angle)
{
	m_angle = angle;

	filterAngle();
}


void Angle::addAngle(f32 deltaAngle)
{
	m_angle += deltaAngle;

	filterAngle();
}


void Angle::filterAngle()
{
	m_angle = std::fmod(m_angle, 360.0f);
	if (m_angle < 0)
		m_angle += 360.0f;
}

//###########################################################################

Angle::operator f32() const
{
	return m_angle;
}


Angle& Angle::operator= (const Angle& angle)
{
	m_angle = angle.m_angle;
	return *this;
}

//--------------------------------------------------------------------------

Angle Angle::operator+ (f32 angle) const
{
	return Angle(m_angle + angle);
}


Angle& Angle::operator+= (f32 angle)
{
	addAngle(angle);
	return *this;
}


Angle Angle::operator- (f32 angle) const
{
	return Angle(m_angle - angle);
}


Angle& Angle::operator-= (f32 angle)
{
	addAngle(-angle);
	return *this;
}


Angle Angle::operator* (f32 angle) const
{
	return Angle(m_angle * angle);
}


Angle& Angle::operator*= (f32 angle)
{
	setAngle(m_angle * angle);
	return *this;
}


Angle Angle::operator/ (f32 angle) const
{
	return Angle(m_angle / angle);
}


Angle& Angle::operator/= (f32 angle)
{
	setAngle(m_angle / angle);
	return *this;
}

//--------------------------------------------------------------------------

bool Angle::operator> (f32 angle) const
{
	return (m_angle > angle);
}


bool Angle::operator< (f32 angle) const
{
	return (m_angle < angle);
}


END_NAMESPACE_CA_UTILITY


CodeAdapter::Utility::Angle operator+ (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right)
{
	return{ left + static_cast<CodeAdapter::f32>(right) };
}


CodeAdapter::Utility::Angle operator- (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right)
{
	return{ left - static_cast<CodeAdapter::f32>(right) };
}


CodeAdapter::Utility::Angle operator* (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right)
{
	return{ left * static_cast<CodeAdapter::f32>(right) };
}


CodeAdapter::Utility::Angle operator/ (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right)
{
	return{ left / static_cast<CodeAdapter::f32>(right) };
}

//--------------------------------------------------------------------------

bool operator> (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right)
{
	return{ left > static_cast<CodeAdapter::f32>(right) };
}


bool operator< (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right)
{
	return{ left < static_cast<CodeAdapter::f32>(right) };
}

