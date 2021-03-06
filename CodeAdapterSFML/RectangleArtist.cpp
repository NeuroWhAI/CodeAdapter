#include "RectangleArtist.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Size.h"
#include "CodeAdapter\Rectangle.h"




RectangleArtist::RectangleArtist(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
{

}


RectangleArtist::~RectangleArtist()
{

}

//###########################################################################

void RectangleArtist::beginDrawRectangle(f32 thickness)
{
	m_drawRect.setOutlineThickness(thickness);
	m_drawRect.setFillColor(sf::Color::Transparent);

	updateRenderTransform(m_transform);
}


void RectangleArtist::endDrawRectangle()
{
	m_drawRect.setOutlineThickness(1.0f);
	m_drawRect.setFillColor(sf::Color::White);

	m_renderStates.transform = sf::Transform::Identity;
}


void RectangleArtist::drawRectangle(i32 x, i32 y, i32 width, i32 height, const Color& color)
{
	drawRectangle(static_cast<float>(x), static_cast<float>(y),
		static_cast<float>(width), static_cast<float>(height),
		color);
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


void RectangleArtist::drawRectangle(f32 x, f32 y, f32 width, f32 height, const Color& color)
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
	updateRenderTransform(m_transform);
}


void RectangleArtist::endFillRectangle()
{
	m_renderStates.transform = sf::Transform::Identity;
}


void RectangleArtist::fillRectangle(i32 x, i32 y, i32 width, i32 height, const Color& color)
{
	fillRectangle(static_cast<float>(x), static_cast<float>(y),
		static_cast<float>(width), static_cast<float>(height),
		color);
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


void RectangleArtist::fillRectangle(f32 x, f32 y, f32 width, f32 height, const Color& color)
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

