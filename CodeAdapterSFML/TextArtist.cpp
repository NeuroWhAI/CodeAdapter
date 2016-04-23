#include "TextArtist.h"

#include "CodeAdapter\String.h"
#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Font.h"




TextArtist::TextArtist(SharedObject<sf::RenderWindow>& sharedWin,
	SharedObject<sf::Text>& sharedFontText)
	: m_sharedWin(sharedWin)
	, m_renderStates(sf::RenderStates::Default)
	
	, m_text(nullptr)
	, m_sharedFontText(sharedFontText)
{

}


TextArtist::~TextArtist()
{

}

//###########################################################################

void TextArtist::updateRenderTransform()
{
	m_renderStates.transform.translate(transform.position.x,
		transform.position.y);
	m_renderStates.transform.rotate(transform.angle);
	m_renderStates.transform.scale(transform.scale.x,
		transform.scale.y);
}

//###########################################################################

void TextArtist::beginDrawString(Font& font, const Color& color)
{
	font.attachToGraphics();

	m_text = m_sharedFontText.getObject();
	m_text->setColor(sf::Color(color.getRgba()));

	updateRenderTransform();
}


void TextArtist::endDrawString()
{
	m_text = nullptr;

	m_renderStates.transform = sf::Transform::Identity;
}


void TextArtist::drawString(const String& text, int x, int y)
{
	drawString(text, static_cast<float>(x), static_cast<float>(y));
}


void TextArtist::drawString(const String& text, const Point& location)
{
	drawString(text, location.x, location.y);
}


void TextArtist::drawString(const String& text, float x, float y)
{
	m_text->setString(text.getWStr());
	m_text->setPosition(x, y);

	m_sharedWin.getObject()->draw(*m_text, m_renderStates);
}


void TextArtist::drawString(const String& text, const PointF& location)
{
	drawString(text, location.x, location.y);
}

