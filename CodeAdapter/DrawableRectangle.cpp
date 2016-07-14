#include "DrawableRectangle.h"

#include "Graphics.h"
#include "Transform.h"

#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_DRAWING


DrawableRectangle::DrawableRectangle()
	: edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableRectangle::DrawableRectangle(const RectangleF& rect)
	: RectangleF(rect)

	, edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableRectangle::DrawableRectangle(const f32& x, const f32& y,
	const f32& width, const f32& height)
	: RectangleF(x, y, width, height)
	
	, edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableRectangle::DrawableRectangle(const PointF& location,
	const SizeF& size)
	: RectangleF(location, size)

	, edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableRectangle::~DrawableRectangle()
{

}

//###########################################################################

void DrawableRectangle::onDraw(Graphics& g, const Transform& parentTransform)
{
	auto& artist = g.rectangleArtist;


	artist->beginFillRectangle();

	artist->fillRectangle(x, y, width, height, fillColor);

	artist->endFillRectangle();


	artist->beginDrawRectangle(edgeWidth);

	artist->drawRectangle(x, y, width, height, edgeColor);

	artist->endDrawRectangle();
}


END_NAMESPACE_CA_DRAWING

