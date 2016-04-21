#include "LineArtist.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"




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
}


void LineArtist::endDrawLine()
{
	m_thickness = 0.0f;
}


void LineArtist::drawLine(i32 x1, i32 y1, i32 x2, i32 y2, const Color& color)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].color = sf::Color(color.getRgba());
	line[0].position = sf::Vector2f(static_cast<float>(x1),
		static_cast<float>(y1));
	line[1].color = sf::Color(color.getRgba());
	line[1].position = sf::Vector2f(static_cast<float>(x2),
		static_cast<float>(y2));

	m_sharedWin.getObject()->draw(line, m_renderStates);
}


void LineArtist::drawLine(const Point& point1, const Point& point2, const Color& color)
{
	drawLine(point1.x, point1.y,
		point2.x, point2.y,
		color);
}


void LineArtist::drawLine(const Point* vertexArray[], usize vertexCount, const Color& color, bool closed)
{
	sf::VertexArray vertexList(closed ? sf::LinesStrip : sf::Lines,
		vertexCount);

	sf::Color sfColor = sf::Color(color.getRgba());

	for (std::size_t i = 0; i < vertexCount; ++i)
	{
		vertexList[i].color = sfColor;
		vertexList[i].position = {
			static_cast<float>(vertexArray[i]->x),
			static_cast<float>(vertexArray[i]->y)
		};
	}

	m_sharedWin.getObject()->draw(vertexList, m_renderStates);
}


void LineArtist::drawLine(f32 x1, f32 y1, f32 x2, f32 y2, const Color& color)
{
	sf::VertexArray line(sf::Lines, 2);
	line[0].color = sf::Color(color.getRgba());
	line[0].position = sf::Vector2f(x1, y1);
	line[1].color = sf::Color(color.getRgba());
	line[1].position = sf::Vector2f(x2, y2);

	m_sharedWin.getObject()->draw(line, m_renderStates);
}


void LineArtist::drawLine(const PointF& point1, const PointF& point2, const Color& color)
{
	drawLine(point1.x, point1.y,
		point2.x, point2.y,
		color);
}


void LineArtist::drawLine(const PointF* vertexArray[], usize vertexCount, const Color& color, bool closed)
{
	sf::VertexArray vertexList(closed ? sf::LinesStrip : sf::Lines,
		vertexCount);

	sf::Color sfColor = sf::Color(color.getRgba());

	for (std::size_t i = 0; i < vertexCount; ++i)
	{
		vertexList[i].color = sfColor;
		vertexList[i].position = {
			vertexArray[i]->x,
			vertexArray[i]->y
		};
	}

	m_sharedWin.getObject()->draw(vertexList, m_renderStates);
}

