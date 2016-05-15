#include "ScrollBar.h"

#include "Touch.h"

#include "Transform.h"
#include "Graphics.h"

#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


ScrollBar::ScrollBar()
	: Control(false)

	, m_maxValue(1)
	, m_value(0)
	, m_barControlMode(false)

	, m_barColor({200, 200, 200})
{

}


ScrollBar::~ScrollBar()
{

}

//###########################################################################

void ScrollBar::onValueChanged(const EventArgs& args)
{
	if (WhenValueChanged)
	{
		WhenValueChanged(args);
	}
}

//###########################################################################

void ScrollBar::onTouchDown(const TouchEventArgs& args)
{
	Control::onTouchDown(args);


	if (m_barRect.containsPoint(static_cast<f32>(args.x),
		static_cast<f32>(args.y)))
	{
		// 바 컨트롤 상태 설정
		m_barControlMode = true;
	}
}

//###########################################################################

void ScrollBar::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	if (System::Touch::getInstance()->isUp())
	{
		// 바 컨트롤 상태 해제
		m_barControlMode = false;
	}


	m_barRect = onUpdateScrollBar(parentTransform, localCursor, m_barControlMode);
}


void ScrollBar::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	auto& rectArtist = g.rectangleArtist;
	rectArtist->initialize(parentTransform);

	rectArtist->beginFillRectangle();
	rectArtist->drawRectangle(m_barRect, m_barColor);
	rectArtist->endFillRectangle();
}

//###########################################################################

void ScrollBar::setMaxValue(f32 maxValue)
{
	m_maxValue = maxValue;

	if (m_value > maxValue)
	{
		setValue(maxValue);
	}
}


f32 ScrollBar::getMaxValue() const
{
	return m_maxValue;
}


void ScrollBar::setValue(f32 value)
{
	if (value > m_maxValue)
		value = m_maxValue;

	if (m_value != value)
	{
		m_value = value;

		EventArgs args;

		onValueChanged(args);
	}
}


f32 ScrollBar::getValue() const
{
	return m_value;
}

//###########################################################################

void ScrollBar::setBarColor(const Color& barColor)
{
	m_barColor = barColor;
}


const ScrollBar::Color& ScrollBar::getBarColor() const
{
	return m_barColor;
}


END_NAMESPACE_CA_UI

