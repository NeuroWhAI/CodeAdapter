#ifndef __CA__DRAWABLE_H__
#define __CA__DRAWABLE_H__


#include "BasicDeclaration.h"

#include "Transform.h"




BEGIN_NAMESPACE_CA_DRAWING


class Drawable
{
public:
	Drawable();
	virtual ~Drawable();


protected:
	bool m_visible;


public:
	Transform transform;


public:
	void draw(Graphics& g, const Transform& parentTransform);


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform) = 0;


public:
	virtual void setVisible(bool visible);
	bool isVisible() const;
};


END_NAMESPACE_CA_DRAWING


#endif