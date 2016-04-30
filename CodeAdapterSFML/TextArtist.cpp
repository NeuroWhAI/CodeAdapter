#include "TextArtist.h"

#include "CodeAdapter\UsingSharable.h"

#include "CodeAdapter\String.h"
#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Font.h"




TextArtist::TextArtist(SharedObject<sf::RenderWindow>& sharedWin,
	SharedObject<sf::Text>& sharedFontText)
	: m_sharedWin(sharedWin)
	
	, m_text(nullptr)
	, m_sharedFontText(sharedFontText)
{

}


TextArtist::~TextArtist()
{

}

//###########################################################################

void TextArtist::beginDrawString(Font& font)
{
	CodeAdapter::Utility::UsingSharable shareFont(font);

	m_text = m_sharedFontText.getObject();

	updateRenderTransform(transform);
}


void TextArtist::endDrawString()
{
	m_text = nullptr;

	m_renderStates.transform = sf::Transform::Identity;
}


void TextArtist::drawString(const String& text, i32 x, i32 y, const Color& color)
{
	drawString(text, static_cast<float>(x), static_cast<float>(y), color);
}


void TextArtist::drawString(const String& text, const Point& location, const Color& color)
{
	drawString(text, location.x, location.y, color);
}


void TextArtist::drawString(const String& text, f32 x, f32 y, const Color& color)
{
	m_text->setString(text.getWStr());
	m_text->setPosition(x, y);
	m_text->setColor(sf::Color(color.getRgba()));

	m_sharedWin.getObject()->draw(*m_text, m_renderStates);
}


void TextArtist::drawString(const String& text, const PointF& location, const Color& color)
{
	drawString(text, location.x, location.y, color);
}

