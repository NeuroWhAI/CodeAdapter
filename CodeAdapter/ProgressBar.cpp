#include "ProgressBar.h"

#include <numeric>

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


ProgressBar::ProgressBar()
	: Control(false)

	, m_value(0)
	, m_minValue(0)
	, m_maxValue(100)

	, m_barColor(Color(0, 122, 204))
{

}


ProgressBar::~ProgressBar()
{

}

//###########################################################################

void ProgressBar::onMaxValue(const ValueFEventArgs& args)
{
	if (WhenMaxValue)
	{
		WhenMaxValue(args);
	}
}


void ProgressBar::onMinValue(const ValueFEventArgs& args)
{
	if (WhenMinValue)
	{
		WhenMinValue(args);
	}
}

//###########################################################################

void ProgressBar::onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
	const Transform& localTransform, const PointF& localCursor)
{
	// Empty
}


void ProgressBar::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	const auto& position = getPosition();
	const auto& size = getSize();


	auto& rectArtist = g.rectangleArtist;


	const f32 barStand = m_value - m_minValue;
	const f32 barUnder = m_maxValue - m_minValue;

	f32 barWidth = size.width;

	if (std::abs(barUnder) > std::numeric_limits<f32>::epsilon())
		barWidth = barStand / barUnder * size.width;

	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(position, SizeF(barWidth, size.height), m_barColor);
	rectArtist->endFillRectangle();


	auto font = m_font.lock();
	if (font)
	{
		auto& textArtist = g.textArtist;


		textArtist->beginDrawString(*font);
		textArtist->drawString(getText(),
			position.x + size.width / 2,
			position.y + size.height / 2,
			m_foreColor, Drawing::TextAligns::Center);
		textArtist->endDrawString();
	}
}

//###########################################################################

f32 ProgressBar::getValue() const noexcept
{
	return m_value;
}


void ProgressBar::setValue(f32 value)
{
	if (value < m_minValue)
		value = m_minValue;
	else if (value > m_maxValue)
		value = m_maxValue;

	if (value >= m_maxValue && m_value < m_maxValue)
	{
		m_value = value;

		ValueFEventArgs args{ value };
		onMaxValue(args);
	}
	else if (value <= m_minValue && m_value > m_minValue)
	{
		m_value = value;

		ValueFEventArgs args{ value };
		onMinValue(args);
	}
	else
	{
		m_value = value;
	}
}


void ProgressBar::addValue(f32 delta)
{
	setValue(m_value + delta);
}


f32 ProgressBar::getMinValue() const noexcept
{
	return m_minValue;
}


void ProgressBar::setMinValue(f32 minValue)
{
	if (minValue > m_maxValue)
		minValue = m_maxValue;

	m_minValue = minValue;

	// 값 범위 재평가
	setValue(m_value);
}


f32 ProgressBar::getMaxValue() const noexcept
{
	return m_maxValue;
}


void ProgressBar::setMaxValue(f32 maxValue)
{
	if (maxValue < m_minValue)
		maxValue = m_minValue;

	m_maxValue = maxValue;

	// 값 범위 재평가
	setValue(m_value);
}


auto ProgressBar::getBarColor() const noexcept -> const Color&
{
	return m_barColor;
}


void ProgressBar::setBarColor(const Color& barColor)
{
	m_barColor = barColor;
}


END_NAMESPACE_CA_UI

