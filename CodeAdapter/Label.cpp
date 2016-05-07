#include "Label.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"




BEGIN_NAMESPACE_CA_UI


Label::Label()
	: m_text("")
	, m_textColor(Color::Black)
{

}


Label::~Label()
{

}

//###########################################################################

void Label::onUpdateControl(const Transform& parentTransform)
{
	// Empty
}


void Label::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->transform = parentTransform;


		artist->beginDrawString(*m_font.lock());

		artist->drawString(m_text, m_position, m_textColor);

		artist->endDrawString();
	}
}

//###########################################################################

void Label::setText(const Utility::String& text)
{
	m_text = text;
}


const Utility::String& Label::getText() const
{
	return m_text;
}


void Label::setFont(std::weak_ptr<Drawing::Font> font)
{
	m_font = font;
}


void Label::setTextColor(const Color& textColor)
{
	m_textColor = textColor;
}


const Drawing::Color& Label::getTextColor() const
{
	return m_textColor;
}


END_NAMESPACE_CA_UI

