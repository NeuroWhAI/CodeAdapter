#include "RectangleArtist.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Size.h"
#include "CodeAdapter\Rectangle.h"




RectangleArtist::RectangleArtist(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
	, m_renderStates(sf::RenderStates::Default)
{

}


RectangleArtist::~RectangleArtist()
{

}

//###########################################################################

void RectangleArtist::updateRenderTransform()
{
	m_renderStates.transform.translate(transform.position.x,
		transform.position.y);
	m_renderStates.transform.rotate(transform.angle);
	m_renderStates.transform.scale(transform.scale.x,
		transform.scale.y);
}

//###########################################################################

void RectangleArtist::beginDrawRectangle(float thickness)
{
	m_drawRect.setOutlineThickness(thickness);
	m_drawRect.setFillColor(sf::Color::Transparent);

	updateRenderTransform();
}


void RectangleArtist::endDrawRectangle()
{
	m_drawRect.setOutlineThickness(1.0f);
	m_drawRect.setFillColor(sf::Color::White);

	m_renderStates.transform = sf::Transform::Identity;
}


void RectangleArtist::drawRectangle(int x, int y, int width, int height, const Color& color)
{
	m_drawRect.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_drawRect.setSize(sf::Vector2f(static_cast<float>(width),
		static_cast<float>(height)));
	m_drawRect.setOutlineColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_drawRect, m_renderStates);
}


void RectangleArtist::drawRectangle(const Point& location, const Size& size, const Color& color)
{
	drawRectangle(location.x, location.y,
		size.width, size.height,
		color);
}


void RectangleArtist::drawRectangle(const Rectangle& rectangle, const Color& color)
{
	drawRectangle(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}


void RectangleArtist::drawRectangle(float x, float y, float width, float height, const Color& color)
{
	m_drawRect.setPosition(x, y);
	m_drawRect.setSize(sf::Vector2f(width, height));
	m_drawRect.setOutlineColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_drawRect, m_renderStates);
}


void RectangleArtist::drawRectangle(const PointF& location, const SizeF& size, const Color& color)
{
	drawRectangle(location.x, location.y,
		size.width, size.height,
		color);
}


void RectangleArtist::drawRectangle(const RectangleF& rectangle, const Color& color)
{
	drawRectangle(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}

//--------------------------------------------------------------------------

void RectangleArtist::beginFillRectangle()
{
	updateRenderTransform();
}


void RectangleArtist::endFillRectangle()
{
	m_renderStates.transform = sf::Transform::Identity;
}


void RectangleArtist::fillRectangle(int x, int y, int width, int height, const Color& color)
{
	m_fillRect.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_fillRect.setSize(sf::Vector2f(static_cast<float>(width),
		static_cast<float>(height)));
	m_fillRect.setFillColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_fillRect, m_renderStates);
}


void RectangleArtist::fillRectangle(const Point& location, const Size& size, const Color& color)
{
	fillRectangle(location.x, location.y,
		size.width, size.height,
		color);
}


void RectangleArtist::fillRectangle(const Rectangle& rectangle, const Color& color)
{
	fillRectangle(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}


void RectangleArtist::fillRectangle(float x, float y, float width, float height, const Color& color)
{
	m_fillRect.setPosition(x, y);
	m_fillRect.setSize(sf::Vector2f(width, height));
	m_fillRect.setFillColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_fillRect, m_renderStates);
}


void RectangleArtist::fillRectangle(const PointF& location, const SizeF& size, const Color& color)
{
	fillRectangle(location.x, location.y,
		size.width, size.height,
		color);
}


void RectangleArtist::fillRectangle(const RectangleF& rectangle, const Color& color)
{
	fillRectangle(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}

