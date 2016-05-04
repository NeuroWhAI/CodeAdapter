#ifndef __CA__UPDATABLE_H__
#define __CA__UPDATABLE_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


class Updatable
{
public:
	Updatable();
	virtual ~Updatable();


public:
	virtual void update(const Transform& parentTransform, const Point& cursor) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif