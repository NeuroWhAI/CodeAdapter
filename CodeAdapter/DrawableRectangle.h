#ifndef __CA__DRAWABLE_RECTANGLE_H__
#define __CA__DRAWABLE_RECTANGLE_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Drawable.h"
#include "Rectangle.h"

#include "Color.h"




BEGIN_NAMESPACE_CA_DRAWING


class DrawableRectangle : public RectangleF, public Drawable
{
public:
	using Ptr = std::shared_ptr<DrawableRectangle>;


public:
	DrawableRectangle();
	DrawableRectangle(const RectangleF&  rect);
	DrawableRectangle(const f32& x, const f32& y,
		const f32& width, const f32& height);
	DrawableRectangle(const PointF& location,
		const SizeF& size);
	virtual ~DrawableRectangle();


public:
	f32 edgeWidth;
	Color edgeColor;
	Color fillColor;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform);
};


END_NAMESPACE_CA_DRAWING


#endif