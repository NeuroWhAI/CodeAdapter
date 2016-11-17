#ifndef __CA__DRAWABLE_TEXTURE_H__
#define __CA__DRAWABLE_TEXTURE_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Drawable.h"

#include "Point.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_DRAWING


class DrawableTexture : public Drawable
{
public:
	using Ptr = std::shared_ptr<DrawableTexture>;


public:
	DrawableTexture();
	virtual ~DrawableTexture();


public:
	PointF location;
	Color color;


protected:
	std::weak_ptr<Texture> m_texture;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform);


public:
	void setTexture(std::weak_ptr<Texture> texture);
};


END_NAMESPACE_CA_DRAWING


#endif