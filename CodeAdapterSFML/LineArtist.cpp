#include "LineArtist.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"

#include "CodeAdapter\Vector.h"




LineArtist::LineArtist(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
	, m_renderStates(sf::RenderStates::Default)

	, m_thickness(0.0f)
{

}


LineArtist::~LineArtist()
{

}

//###########################################################################

void LineArtist::updateRenderTransform()
{
	m_renderStates.transform.translate(transform.position.x,
		transform.position.y);
	m_renderStates.transform.rotate(transform.angle);
	m_renderStates.transform.scale(transform.scale.x,
		transform.scale.y);
}

//###########################################################################

void LineArtist::beginDrawLine(f32 thickness)
{
	m_thickness = thickness;

	updateRenderTransform();
}


void LineArtist::endDrawLine()
{
	m_thickness = 0.0f;

	m_renderStates.transform = sf::Transform::Identity;
}


void LineArtist::drawLine(i32 x1, i32 y1, i32 x2, i32 y2, const Color& color)
{
	drawLine(static_cast<f32>(x1), static_cast<f32>(y1),
		static_cast<f32>(x2), static_cast<f32>(y2), color);
}


void LineArtist::drawLine(const Point& point1, const Point& point2, const Color& color)
{
	drawLine(point1.x, point1.y,
		point2.x, point2.y,
		color);
}


void LineArtist::drawLine(f32 x1, f32 y1, f32 x2, f32 y2, const Color& color)
{
	sf::Vertex vtxList[4];

	VectorF begin = { x1, y1 };
	VectorF end = { x2, y2 };

	VectorF direction = end - begin;
	direction.normalize();

	VectorF perpendicularVec = { -direction.y, direction.x };

	VectorF offset = (m_thickness / 2.0f) * perpendicularVec;

	VectorF tempVtxList[4] = {
		{ begin + offset },
		{ end + offset },
		{ end - offset },
		{ begin - offset }
	};

	const sf::Color sfColor = sf::Color(color.getRgba());

	for (i32 i = 0; i < 4; ++i)
	{
		vtxList[i].position = {
			tempVtxList[i].x, tempVtxList[i].y
		};
		vtxList[i].color = sfColor;
	}

	m_sharedWin.getObject()->draw(vtxList, 4, sf::Quads, m_renderStates);
}


void LineArtist::drawLine(const PointF& point1, const PointF& point2, const Color& color)
{
	drawLine(point1.x, point1.y,
		point2.x, point2.y,
		color);
}

