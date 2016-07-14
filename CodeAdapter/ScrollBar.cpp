#include "ScrollBar.h"

#include <numeric>

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

	, m_barColor({ 220, 220, 220 })
	, m_barThicknessRate(0.8f)
	, m_minBarLength(10.0f)
	, m_barLengthScale(2.0f)
{
	m_backColor = { 140, 140, 140 };
}


ScrollBar::~ScrollBar()
{

}

//###########################################################################

void ScrollBar::onValueChanged(const ValueFEventArgs& args)
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

//--------------------------------------------------------------------------

void ScrollBar::onLeaveFocus(const EventArgs& args)
{
	Control::onLeaveFocus(args);


	if (m_barControlMode)
	{
		setOverlayColor(m_touchOverlayColor);
	}
}

//###########################################################################

void ScrollBar::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	if (m_barControlMode && System::Touch::getInstance()->isUp())
	{
		// 바 컨트롤 상태 해제
		m_barControlMode = false;


		setOverlayColor(Color::Transparent);
	}


	m_barRect = onUpdateScrollBar(parentTransform, localCursor, m_barControlMode);
}


void ScrollBar::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	auto& rectArtist = g.rectangleArtist;


	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(m_barRect, m_barColor);
	rectArtist->fillRectangle(m_barRect, getOverlayColor());
	rectArtist->endFillRectangle();
}

//###########################################################################

void ScrollBar::setMaxValue(f32 maxValue)
{
	if (maxValue < std::numeric_limits<f32>::epsilon())
		maxValue = std::numeric_limits<f32>::epsilon();

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
	else if (value < 0)
		value = 0;

	if (m_value != value)
	{
		m_value = value;

		ValueFEventArgs args{ value };
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


void ScrollBar::setBarThicknessRate(f32 rate)
{
	if (rate < std::numeric_limits<f32>::epsilon())
		rate = std::numeric_limits<f32>::epsilon();
	else if (rate > 1)
		rate = 1;

	m_barThicknessRate = rate;
}


f32 ScrollBar::getBarThicknessRate() const
{
	return m_barThicknessRate;
}


void ScrollBar::setMinBarLength(f32 length)
{
	const auto& size = getSize();


	if (length < 1)
		length = 1;
	else if (length > size.height - 1)
		length = size.height - 1;

	m_minBarLength = length;
}


f32 ScrollBar::getMinBarLength() const
{
	return m_minBarLength;
}


void ScrollBar::setBarLengthScale(f32 scale)
{
	if (scale < std::numeric_limits<f32>::epsilon())
		scale = std::numeric_limits<f32>::epsilon();

	m_barLengthScale = scale;
}


f32 ScrollBar::getBarLengthScale() const
{
	return m_barLengthScale;
}


END_NAMESPACE_CA_UI

