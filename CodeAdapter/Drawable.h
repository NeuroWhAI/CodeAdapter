#ifndef __CA__DRAWABLE_H__
#define __CA__DRAWABLE_H__


#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_DRAWING


class Graphics;
class Transform;


class Drawable
{
public:
	Drawable();
	virtual ~Drawable();


public:
	virtual void draw(Graphics& g, const Transform& parentTransform) = 0;
};


END_NAMESPACE_CA_DRAWING


#endif