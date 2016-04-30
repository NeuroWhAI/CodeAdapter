#ifndef __CA__SHARABLE_H__
#define __CA__SHARABLE_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class Sharable
{
public:
	Sharable();
	virtual ~Sharable();


public:
	virtual void attach() = 0;
	virtual void detach() = 0;
};


END_NAMESPACE_CA_UTILITY


#endif