#ifndef __CA__DRAWABLE_ELLIPSE_H__
#define __CA__DRAWABLE_ELLIPSE_H__


#include "BasicDeclaration.h"

#include "Drawable.h"
#include "Rectangle.h"

#include "Color.h"




BEGIN_NAMESPACE_CA_DRAWING


class DrawableEllipse : public RectangleF, public Drawable
{
public:
	DrawableEllipse();
	DrawableEllipse(const RectangleF&  rect);
	DrawableEllipse(const f32& x, const f32& y,
		const f32& width, const f32& height);
	DrawableEllipse(const PointF& location,
		const SizeF& size);
	virtual ~DrawableEllipse();


public:
	f32 edgeWidth;
	Color edgeColor;
	Color fillColor;


public:
	virtual bool containsPoint(const f32& x, const f32& y) const override;
	virtual bool containsPoint(const PointT<f32>& point) const override;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform);
};


END_NAMESPACE_CA_DRAWING


#endif