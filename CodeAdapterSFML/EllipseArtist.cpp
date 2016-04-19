#include "EllipseArtist.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Size.h"
#include "CodeAdapter\Rectangle.h"




EllipseArtist::EllipseArtist(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)
	, m_renderStates(sf::RenderStates::Default)
{

}


EllipseArtist::~EllipseArtist()
{

}

//###########################################################################

void EllipseArtist::updateRenderTransform()
{
	m_renderStates.transform.translate(transform.position.x,
		transform.position.y);
	m_renderStates.transform.rotate(transform.angle);
	m_renderStates.transform.scale(transform.scale.x,
		transform.scale.y);
}

//###########################################################################

void EllipseArtist::beginDrawEllipse(f32 thickness)
{
	m_drawCircle.setOutlineThickness(thickness);
	m_drawCircle.setFillColor(sf::Color::Transparent);

	updateRenderTransform();
}


void EllipseArtist::endDrawEllipse()
{
	m_drawCircle.setOutlineThickness(1.0f);
	m_drawCircle.setFillColor(sf::Color::White);

	m_renderStates.transform = sf::Transform::Identity;
}


void EllipseArtist::drawEllipse(i32 x, i32 y, i32 width, i32 height, const Color& color)
{
	m_drawCircle.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_drawCircle.setRadius(width / 2.0f);
	m_drawCircle.setScale(1.0f, static_cast<float>(height) / width);
	m_drawCircle.setOutlineColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_drawCircle, m_renderStates);
}


void EllipseArtist::drawEllipse(const Point& location, const Size& size, const Color& color)
{
	drawEllipse(location.x, location.y,
		size.width, size.height,
		color);
}


void EllipseArtist::drawEllipse(const Rectangle& rectangle, const Color& color)
{
	drawEllipse(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}


void EllipseArtist::drawEllipse(f32 x, f32 y, f32 width, f32 height, const Color& color)
{
	m_drawCircle.setPosition(x, y);
	m_drawCircle.setRadius(width / 2.0f);
	m_drawCircle.setScale(1.0f, height / width);
	m_drawCircle.setOutlineColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_drawCircle, m_renderStates);
}


void EllipseArtist::drawEllipse(const PointF& location, const SizeF& size, const Color& color)
{
	drawEllipse(location.x, location.y,
		size.width, size.height,
		color);
}


void EllipseArtist::drawEllipse(const RectangleF& rectangle, const Color& color)
{
	drawEllipse(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}

//--------------------------------------------------------------------------

void EllipseArtist::beginFillEllipse()
{
	updateRenderTransform();
}


void EllipseArtist::endFillEllipse()
{
	m_renderStates.transform = sf::Transform::Identity;
}


void EllipseArtist::fillEllipse(i32 x, i32 y, i32 width, i32 height, const Color& color)
{
	m_fillCircle.setPosition(static_cast<float>(x), static_cast<float>(y));
	m_fillCircle.setRadius(width / 2.0f);
	m_fillCircle.setScale(1.0f, static_cast<float>(height) / width);
	m_fillCircle.setFillColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_fillCircle, m_renderStates);
}


void EllipseArtist::fillEllipse(const Point& location, const Size& size, const Color& color)
{
	fillEllipse(location.x, location.y,
		size.width, size.height,
		color);
}


void EllipseArtist::fillEllipse(const Rectangle& rectangle, const Color& color)
{
	fillEllipse(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}


void EllipseArtist::fillEllipse(f32 x, f32 y, f32 width, f32 height, const Color& color)
{
	m_fillCircle.setPosition(x, y);
	m_fillCircle.setRadius(width / 2.0f);
	m_fillCircle.setScale(1.0f, height / width);
	m_fillCircle.setFillColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(m_fillCircle, m_renderStates);
}


void EllipseArtist::fillEllipse(const PointF& location, const SizeF& size, const Color& color)
{
	fillEllipse(location.x, location.y,
		size.width, size.height,
		color);
}


void EllipseArtist::fillEllipse(const RectangleF& rectangle, const Color& color)
{
	fillEllipse(rectangle.x, rectangle.y,
		rectangle.width, rectangle.height,
		color);
}

