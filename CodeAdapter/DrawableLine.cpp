#include "DrawableLine.h"

#include "Graphics.h"
#include "Transform.h"

#include "LineArtist.h"




BEGIN_NAMESPACE_CA_DRAWING


DrawableLine::DrawableLine()
	: color(Color::Black)
	, thickness(1.0f)
{

}


DrawableLine::DrawableLine(const PointF& begin, const PointF& end)
	: LineF(begin, end)
	
	, color(Color::Black)
	, thickness(1.0f)
{

}


DrawableLine::DrawableLine(f32 beginX, f32 beginY, f32 endX, f32 endY)
	: LineF(beginX, beginY, endX, endY)
	
	, color(Color::Black)
	, thickness(1.0f)
{

}


DrawableLine::~DrawableLine()
{

}

//###########################################################################

void DrawableLine::onDraw(Graphics& g, const Transform& parentTransform)
{
	auto& artist = g.lineArtist;


	artist->initialize(parentTransform);


	artist->beginDrawLine(thickness);

	artist->drawLine(begin, end, color);

	artist->endDrawLine();
}


END_NAMESPACE_CA_DRAWING

