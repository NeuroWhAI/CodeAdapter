#include "TextArtist.h"

#include "CodeAdapter\UsingSharable.h"

#include "CodeAdapter\String.h"
#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Color.h"
#include "CodeAdapter\Point.h"
#include "CodeAdapter\Rectangle.h"
#include "CodeAdapter\TextAligns.h"
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

	updateRenderTransform(m_transform);
}


void TextArtist::endDrawString()
{
	m_text = nullptr;

	m_renderStates.transform = sf::Transform::Identity;
}


auto TextArtist::getBoundRectangle(const String& text) -> RectangleF
{
	m_text->setString(text.getWStr());

	auto textRect = m_text->getLocalBounds();


	return RectangleF(textRect.left, textRect.top,
		textRect.width, textRect.height);
}


void TextArtist::drawString(const String& text, i32 x, i32 y, const Color& color,
	TextAligns align)
{
	drawString(text, static_cast<float>(x), static_cast<float>(y), color, align);
}


void TextArtist::drawString(const String& text, const Point& location, const Color& color,
	TextAligns align)
{
	drawString(text, location.x, location.y, color, align);
}


void TextArtist::drawString(const String& text, f32 x, f32 y, const Color& color,
	TextAligns align)
{
	m_text->setString(text.getWStr());
	m_text->setPosition(x, y);
	m_text->setColor(sf::Color(color.getRgba()));

	auto textRect = m_text->getLocalBounds();

	sf::Vector2f origin = { 0, 0 };

	switch (align)
	{
	case TextAligns::Left:
		origin.x = textRect.width;
		origin.y = textRect.height / 2.0f;
		break;

	case TextAligns::Right:
		origin.y = textRect.height / 2.0f;
		break;

	case TextAligns::Top:
		origin.x = textRect.width / 2.0f;
		origin.y = textRect.height;
		break;

	case TextAligns::Bottom:
		origin.x = textRect.width / 2.0f;
		break;

	case TextAligns::LeftTop:
		origin.x = textRect.width;
		origin.y = textRect.height;
		break;

	case TextAligns::RightTop:
		origin.y = textRect.height;
		break;

	case TextAligns::LeftBottom:
		origin.x = textRect.width;
		break;

	case TextAligns::RightBottom:
		origin.x = 0.0f;
		origin.y = 0.0f;
		break;

	case TextAligns::Center:
		origin.x = textRect.width / 2.0f;
		origin.y = textRect.height / 2.0f;
		break;
	}

	origin.x += textRect.left;
	origin.y += textRect.top;

	m_text->setOrigin(origin);

	m_sharedWin.getObject()->draw(*m_text, m_renderStates);
}


void TextArtist::drawString(const String& text, const PointF& location, const Color& color,
	TextAligns align)
{
	drawString(text, location.x, location.y, color, align);
}

