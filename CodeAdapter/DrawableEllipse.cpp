#include "DrawableEllipse.h"

#include <limits>

#include "Graphics.h"
#include "Transform.h"

#include "EllipseArtist.h"




BEGIN_NAMESPACE_CA_DRAWING


DrawableEllipse::DrawableEllipse()
	: edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableEllipse::DrawableEllipse(const RectangleF& rect)
	: RectangleF(rect)

	, edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableEllipse::DrawableEllipse(const f32& x, const f32& y,
	const f32& width, const f32& height)
	: RectangleF(x, y, width, height)

	, edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableEllipse::DrawableEllipse(const PointF& location,
	const SizeF& size)
	: RectangleF(location, size)

	, edgeWidth(0)
	, edgeColor(Color::Black)
	, fillColor(Color::White)
{

}


DrawableEllipse::~DrawableEllipse()
{

}

//###########################################################################

bool DrawableEllipse::containsPoint(const f32& x, const f32& y) const
{
	f32 a = width / 2.0f;
	f32 b = height / 2.0f;

	f32 sx = x - this->x - a;
	f32 sy = y - this->y - b;

	if (std::abs(a) < std::numeric_limits<f32>::epsilon()
		|| std::abs(b) < std::numeric_limits<f32>::epsilon())
	{
		return false;
	}

	return (((sx * sx) / (a * a) + (sy * sy) / (b * b)) < 1.0f);
}


bool DrawableEllipse::containsPoint(const PointT<f32>& point) const
{
	return containsPoint(point.x, point.y);
}

//###########################################################################

void DrawableEllipse::onDraw(Graphics& g, const Transform& parentTransform)
{
	auto& artist = g.ellipseArtist;


	artist->beginFillEllipse();

	artist->fillEllipse(x, y, width, height, fillColor);

	artist->endFillEllipse();


	artist->beginDrawEllipse(edgeWidth);

	artist->drawEllipse(x, y, width, height, edgeColor);

	artist->endDrawEllipse();
}


END_NAMESPACE_CA_DRAWING

