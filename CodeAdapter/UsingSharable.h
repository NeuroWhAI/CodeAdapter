#ifndef __CA__USING_SHARABLE_H__
#define __CA__USING_SHARABLE_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class UsingSharable
{
public:
	explicit UsingSharable(Sharable& target);
	virtual ~UsingSharable();


protected:
	Sharable& m_target;
};


END_NAMESPACE_CA_UTILITY


#endif