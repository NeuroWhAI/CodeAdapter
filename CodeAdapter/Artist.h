#ifndef __CA__ARTIST_H__
#define __CA__ARTIST_H__


#include "Definition.h"
#include "CAType.h"

#include "Transform.h"




BEGIN_NAMESPACE_CA_DRAWING


class Artist
{
public:
	Artist();
	virtual ~Artist();


public:
	Transform transform;
};


END_NAMESPACE_CA_DRAWING


#endif