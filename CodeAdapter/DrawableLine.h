#ifndef __CA__DRAWABLE_LINE_H__
#define __CA__DRAWABLE_LINE_H__


#include "BasicDeclaration.h"

#include "Drawable.h"
#include "Line.h"

#include "Color.h"




BEGIN_NAMESPACE_CA_DRAWING


class DrawableLine : public LineF, public Drawable
{
public:
	DrawableLine();
	DrawableLine(const PointF& begin, const PointF& end);
	DrawableLine(f32 beginX, f32 beginY, f32 endX, f32 endY);
	virtual ~DrawableLine();


public:
	Color color;
	f32 thickness;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform);
};


END_NAMESPACE_CA_DRAWING


#endif