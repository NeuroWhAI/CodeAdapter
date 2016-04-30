#include "TextureArtist.h"

#include "CodeAdapter\UsingSharable.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Rectangle.h"
#include "CodeAdapter\Texture.h"




TextureArtist::TextureArtist(SharedObject<sf::RenderWindow>& sharedWin,
	SharedObject<sf::Texture>& sharedTexture)
	: m_sharedWin(sharedWin)

	, m_sharedTexture(sharedTexture)
{

}


TextureArtist::~TextureArtist()
{

}

//###########################################################################

void TextureArtist::beginDrawTexture()
{
	updateRenderTransform(transform);
}


void TextureArtist::endDrawTexture()
{
	m_renderStates.transform = sf::Transform::Identity;
}


void TextureArtist::drawTexture(Texture& texture, i32 x, i32 y,
	const Color& maskColor)
{
	drawTexture(texture, static_cast<f32>(x), static_cast<f32>(y),
		maskColor);
}


void TextureArtist::drawTexture(Texture& texture, i32 x, i32 y,
	const Rectangle& sliceRectangle,
	const Color& maskColor)
{
	drawTexture(texture, static_cast<f32>(x), static_cast<f32>(y),
		sliceRectangle, maskColor);
}


void TextureArtist::drawTexture(Texture& texture, const Point& location,
	const Color& maskColor)
{
	drawTexture(texture, static_cast<f32>(location.x), static_cast<f32>(location.y),
		maskColor);
}


void TextureArtist::drawTexture(Texture& texture, const Point& location,
	const Rectangle& sliceRectangle,
	const Color& maskColor)
{
	drawTexture(texture, static_cast<f32>(location.x), static_cast<f32>(location.y),
		sliceRectangle, maskColor);
}


void TextureArtist::drawTexture(Texture& texture, f32 x, f32 y,
	const Color& maskColor)
{
	CodeAdapter::Utility::UsingSharable shareTexture(texture);

	m_sprite.setTexture(*m_sharedTexture.getObject(), true);
	m_sprite.setPosition(x, y);
	m_sprite.setColor(sf::Color(maskColor.getRgba()));

	m_sharedWin.getObject()->draw(m_sprite, m_renderStates);
}


void TextureArtist::drawTexture(Texture& texture, f32 x, f32 y,
	const Rectangle& sliceRectangle,
	const Color& maskColor)
{
	CodeAdapter::Utility::UsingSharable shareTexture(texture);

	m_sprite.setTexture(*m_sharedTexture.getObject());
	m_sprite.setPosition(x, y);
	m_sprite.setColor(sf::Color(maskColor.getRgba()));
	m_sprite.setTextureRect(sf::IntRect(sliceRectangle.x, sliceRectangle.y,
		sliceRectangle.width, sliceRectangle.height));

	m_sharedWin.getObject()->draw(m_sprite, m_renderStates);
}


void TextureArtist::drawTexture(Texture& texture, const PointF& location,
	const Color& maskColor)
{
	drawTexture(texture, location.x, location.y, maskColor);
}


void TextureArtist::drawTexture(Texture& texture, const PointF& location,
	const Rectangle& sliceRectangle,
	const Color& maskColor)
{
	drawTexture(texture, location.x, location.y, sliceRectangle, maskColor);
}

