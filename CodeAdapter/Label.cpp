#include "Label.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"




BEGIN_NAMESPACE_CA_UI


Label::Label()
	: Control(false)
	
	, m_text("")
	, m_textColor(Color::Black)
	, m_textMargin(0, 0)
{

}


Label::~Label()
{

}

//###########################################################################

void Label::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	// Empty
}


void Label::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(m_text,
			m_position.x + m_textMargin.x,
			m_position.y + m_size.height / 2.0f + m_textMargin.y,
			m_textColor,
			Drawing::TextAligns::Right);

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


const Label::Color& Label::getTextColor() const
{
	return m_textColor;
}


void Label::setTextMargin(const PointF& margin)
{
	m_textMargin = margin;
}


const Label::PointF& Label::getTextMargin() const
{
	return m_textMargin;
}


END_NAMESPACE_CA_UI

