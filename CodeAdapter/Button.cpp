#include "Button.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


Button::Button()
	: Control(false)
{

}


Button::~Button()
{

}

//###########################################################################

void Button::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	// Empty
}


void Button::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	const auto& position = getPosition();
	const auto& size = getSize();


	// ��� �׸���
	auto& rectArtist = g.rectangleArtist;
	rectArtist->initialize(parentTransform);

	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(position, size, m_backColor);
	rectArtist->fillRectangle(position, size, getOverlayColor());
	rectArtist->endFillRectangle();


	// �ؽ�Ʈ �׸���
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(getText(),
			position.x + size.width / 2.0f,
			position.y + size.height / 2.0f,
			m_foreColor,
			Drawing::TextAligns::Center);

		artist->endDrawString();
	}
}


END_NAMESPACE_CA_UI

