#include "Label.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"




BEGIN_NAMESPACE_CA_UI


Label::Label()
	: Control(false)
	
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
	auto font = m_font.lock();
	if (font)
	{
		const auto& position = getPosition();
		const auto& size = getSize();


		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*font);

		artist->drawString(getText(),
			position.x + m_textMargin.x,
			position.y + size.height / 2.0f + m_textMargin.y,
			m_foreColor,
			Drawing::TextAligns::Right);

		artist->endDrawString();
	}
}

//###########################################################################

void Label::setTextMargin(const PointF& margin)
{
	m_textMargin = margin;
}


const Label::PointF& Label::getTextMargin() const
{
	return m_textMargin;
}


END_NAMESPACE_CA_UI

