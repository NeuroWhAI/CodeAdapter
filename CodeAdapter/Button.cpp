#include "Button.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


Button::Button()
	: Control(false)

	, m_overlayColor(Color::Transparent)
	, m_focusColor(Color(Color::Cyan, 64))
	, m_touchColor(Color(Color::Cyan, 128))
{

}


Button::~Button()
{

}

//###########################################################################

void Button::onTouchDown(const TouchEventArgs& args)
{
	Control::onTouchDown(args);


	m_overlayColor = m_touchColor;
}


void Button::onTouchUp(const TouchEventArgs& args)
{
	Control::onTouchUp(args);


	m_overlayColor = m_focusColor;
}

//--------------------------------------------------------------------------

void Button::onEnterFocus(const EventArgs& args)
{
	Control::onEnterFocus(args);


	m_overlayColor = m_focusColor;
}


void Button::onLeaveFocus(const EventArgs& args)
{
	Control::onLeaveFocus(args);


	m_overlayColor = Color::Transparent;
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


	// 배경 그리기
	auto& rectArtist = g.rectangleArtist;
	rectArtist->initialize(parentTransform);

	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(position, size, m_overlayColor);
	rectArtist->endFillRectangle();


	// 텍스트 그리기
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

//###########################################################################

void Button::setFocusColor(const Color& focusColor)
{
	m_focusColor = focusColor;
}


const Drawing::Color& Button::getFocusColor() const
{
	return m_focusColor;
}


void Button::setTouchColor(const Color& touchColor)
{
	m_touchColor = touchColor;
}


const Drawing::Color& Button::getTouchColor() const
{
	return m_touchColor;
}


END_NAMESPACE_CA_UI

