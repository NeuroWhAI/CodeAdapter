#ifndef __CA__ARTIST_H__
#define __CA__ARTIST_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Transform.h"




BEGIN_NAMESPACE_CA_DRAWING


class Artist
{
public:
	using Ptr = std::shared_ptr<Artist>;


public:
	Artist();
	virtual ~Artist();


protected:
	Transform m_transform;


public:
	virtual void initialize(const Transform& transform);
};


END_NAMESPACE_CA_DRAWING


#endif