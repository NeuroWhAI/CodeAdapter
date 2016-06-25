#include "CheckBox.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


CheckBox::CheckBox()
	: Control(false)

	, m_textMargin(0, 0)

	, m_bChecked(false)
	, m_boxRate(0.6f)
	, m_boxThickness(3)
	, m_innerBoxRate(0.8f)
	, m_boxColor(Color::White)
	, m_backBoxColor(Color::Gray)
{
	m_backColor = Color::Gray;
}


CheckBox::~CheckBox()
{

}

//###########################################################################

void CheckBox::onCheckedChanged(const EventArgs& args)
{
	if (WhenCheckedChanged)
	{
		WhenCheckedChanged(args);
	}
}

//###########################################################################

void CheckBox::onClick(const TouchEventArgs& args)
{
	Control::onClick(args);


	check(!isChecked());
}

//###########################################################################

void CheckBox::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	// Empty
}


void CheckBox::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	const auto& position = getPosition();
	const auto& size = getSize();


	// 배경 그리기
	auto& rectArtist = g.rectangleArtist;
	rectArtist->initialize(parentTransform);

	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(position, size, m_backColor);
	rectArtist->endFillRectangle();


	// 박스 그리기
	const f32 boxSize = size.height * m_boxRate;
	const f32 middleBoxSize = boxSize - m_boxThickness * 2;
	const f32 innerBoxSize = middleBoxSize * m_innerBoxRate;
	const f32 boxGap = (middleBoxSize - innerBoxSize) / 2;

	PointF boxPosition = position;
	boxPosition.y += size.height / 2 - boxSize / 2;

	rectArtist->beginFillRectangle();

	rectArtist->fillRectangle(boxPosition,
		SizeF(boxSize, boxSize), m_boxColor);

	if (!m_bChecked)
	{
		rectArtist->fillRectangle(boxPosition,
			SizeF(boxSize, boxSize), getOverlayColor());
	}
	
	boxPosition += PointF(m_boxThickness, m_boxThickness);
	rectArtist->fillRectangle(boxPosition,
		SizeF(middleBoxSize, middleBoxSize), m_backBoxColor);

	if (m_bChecked)
	{
		const f32 deltaPosition = boxGap;
		boxPosition += PointF(deltaPosition, deltaPosition);

		rectArtist->fillRectangle(boxPosition,
			SizeF(innerBoxSize, innerBoxSize), m_boxColor);
		rectArtist->fillRectangle(boxPosition,
			SizeF(innerBoxSize, innerBoxSize), getOverlayColor());
	}

	rectArtist->endFillRectangle();


	// 텍스트 그리기
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(getText(),
			position.x + boxSize + m_textMargin.x,
			position.y + size.height / 2.0f + m_textMargin.y,
			m_foreColor,
			Drawing::TextAligns::Right);

		artist->endDrawString();
	}
}

//###########################################################################

void CheckBox::setTextMargin(const PointF& margin)
{
	m_textMargin = margin;
}


const CheckBox::PointF& CheckBox::getTextMargin() const
{
	return m_textMargin;
}


void CheckBox::setBoxColor(const Color& boxColor)
{
	m_boxColor = boxColor;
}


const Drawing::Color& CheckBox::getBoxColor() const
{
	return m_boxColor;
}


void CheckBox::setBackBoxColor(const Color& backBoxColor)
{
	m_backBoxColor = backBoxColor;
}


const Drawing::Color& CheckBox::getBackBoxColor() const
{
	return m_backBoxColor;
}


void CheckBox::setBoxScale(f32 scale) noexcept
{
	m_boxRate = scale;
}


f32 CheckBox::getBoxScale() const noexcept
{
	return m_boxRate;
}


void CheckBox::setBoxThickness(f32 thickness) noexcept
{
	m_boxThickness = thickness;
}


f32 CheckBox::getBoxThickness() const noexcept
{
	return m_boxThickness;
}


void CheckBox::setInnerBoxScale(f32 scale) noexcept
{
	m_innerBoxRate = scale;
}


f32 CheckBox::getInnerBoxScale() const noexcept
{
	return m_innerBoxRate;
}


void CheckBox::check(bool bChecked)
{
	if (bChecked != m_bChecked)
	{
		m_bChecked = bChecked;


		EventArgs args;
		onCheckedChanged(args);
	}
}


void CheckBox::toggle()
{
	m_bChecked = !m_bChecked;


	EventArgs args;
	onCheckedChanged(args);
}


bool CheckBox::isChecked() const noexcept
{
	return m_bChecked;
}


END_NAMESPACE_CA_UI

