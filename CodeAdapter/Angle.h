#ifndef __CA__ANGLE_H__
#define __CA__ANGLE_H__


#include"BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class Angle
{
public:
	Angle();
	Angle(const Angle& angle);
	Angle(Angle&& angle);
	Angle(f32 angle);
	virtual ~Angle();


protected:
	f32 m_angle;


protected:
	void setAngle(f32 angle);
	void addAngle(f32 deltaAngle);
	void filterAngle();


public:
	operator f32() const;
	Angle& operator= (const Angle& angle);

	Angle operator+ (f32 angle) const;
	Angle& operator+= (f32 angle);
	Angle operator- (f32 angle) const;
	Angle& operator-= (f32 angle);
	Angle operator* (f32 angle) const;
	Angle& operator*= (f32 angle);
	Angle operator/ (f32 angle) const;
	Angle& operator/= (f32 angle);

	bool operator> (f32 angle) const;
	bool operator< (f32 angle) const;
};


END_NAMESPACE_CA_UTILITY


CodeAdapter::Utility::Angle operator+ (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right);
CodeAdapter::Utility::Angle operator- (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right);
CodeAdapter::Utility::Angle operator* (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right);
CodeAdapter::Utility::Angle operator/ (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right);

bool operator> (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right);
bool operator< (CodeAdapter::f32 left,
	CodeAdapter::Utility::Angle right);


#endif