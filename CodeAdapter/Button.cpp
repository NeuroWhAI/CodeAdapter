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


	// 덮색 레이어 그리기
	auto& rectArtist = g.rectangleArtist;


	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(position, size, getOverlayColor());
	rectArtist->endFillRectangle();


	// 텍스트 그리기
	auto font = m_font.lock();
	if (font)
	{
		auto& artist = g.textArtist;


		artist->beginDrawString(*font);

		artist->drawString(getText(),
			position.x + size.width / 2.0f,
			position.y + size.height / 2.0f,
			m_foreColor,
			Drawing::TextAligns::Center);

		artist->endDrawString();
	}
}


END_NAMESPACE_CA_UI

