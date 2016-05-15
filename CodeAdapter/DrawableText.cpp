#include "DrawableText.h"

#include "Graphics.h"
#include "Transform.h"

#include "String.h"

#include "TextArtist.h"




BEGIN_NAMESPACE_CA_DRAWING


DrawableText::DrawableText()
	: text("")
	, color(Color::Black)
{

}


DrawableText::DrawableText(const Utility::String& text)
	: text(text)
	, color(Color::Black)
{

}


DrawableText::~DrawableText()
{

}

//###########################################################################

void DrawableText::onDraw(Graphics& g, const Transform& parentTransform)
{
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		auto font = m_font.lock();
		artist->beginDrawString(*font);

		artist->drawString(text, location, color);

		artist->endDrawString();
	}
}

//###########################################################################

void DrawableText::setFont(std::weak_ptr<Font> font)
{
	m_font = font;
}


END_NAMESPACE_CA_DRAWING

