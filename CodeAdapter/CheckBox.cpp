#include "CheckBox.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


CheckBox::CheckBox()
	: Control(false)

	, m_text("")
	, m_textColor(Color::Black)
	, m_textMargin(0, 0)

	, m_bChecked(false)
	, m_boxRate(0.6f)
	, m_boxThickness(3)
	, m_innerBoxRate(0.8f)
	, m_boxColor(Color::White)

	, m_wasTouchDown(false)
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

void CheckBox::onTouchDown(const TouchEventArgs& args)
{
	Control::onTouchDown(args);


	// 박스를 누르고 때었는지 판단하기 위한 플래그
	m_wasTouchDown = true;
}


void CheckBox::onTouchUp(const TouchEventArgs& args)
{
	Control::onTouchUp(args);


	// 박스를 누른뒤 땐거라면
	if (m_wasTouchDown)
	{
		// 토글
		check(!isChecked());


		// 박스 클릭 이벤트 발생
		onCheckedChanged(static_cast<const EventArgs&>(args));


		// 버튼 눌림 플래그 리셋
		m_wasTouchDown = false;
	}
}

//--------------------------------------------------------------------------

void CheckBox::onLeaveFocus(const EventArgs& args)
{
	Control::onLeaveFocus(args);


	// 포커스를 잃으면 버튼 눌림 플래그 리셋
	m_wasTouchDown = false;
}

//###########################################################################

void CheckBox::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	// Empty
}


void CheckBox::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	// 배경 그리기
	auto& rectArtist = g.rectangleArtist;
	rectArtist->initialize(parentTransform);

	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(m_position, m_size, m_backColor);
	rectArtist->endFillRectangle();


	// 박스 그리기
	const f32 boxSize = m_size.height * m_boxRate;
	const f32 middleBoxSize = boxSize - m_boxThickness * 2;
	const f32 innerBoxSize = middleBoxSize * m_innerBoxRate;
	const f32 boxGap = (middleBoxSize - innerBoxSize) / 2;

	PointF boxPosition = m_position;
	boxPosition.y += m_size.height / 2 - boxSize / 2;

	rectArtist->beginFillRectangle();

	rectArtist->fillRectangle(boxPosition,
		SizeF(boxSize, boxSize), m_boxColor);
	
	boxPosition += PointF(m_boxThickness, m_boxThickness);
	rectArtist->fillRectangle(boxPosition,
		SizeF(middleBoxSize, middleBoxSize), m_backColor);

	if (m_bChecked)
	{
		const f32 deltaPosition = boxGap;
		boxPosition += PointF(deltaPosition, deltaPosition);

		rectArtist->fillRectangle(boxPosition,
			SizeF(innerBoxSize, innerBoxSize), m_boxColor);
	}

	rectArtist->endFillRectangle();


	// 텍스트 그리기
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(m_text,
			m_position.x + boxSize + m_textMargin.x,
			m_position.y + m_size.height / 2.0f + m_textMargin.y,
			m_textColor,
			Drawing::TextAligns::Right);

		artist->endDrawString();
	}
}

//###########################################################################

void CheckBox::setText(const Utility::String& text)
{
	m_text = text;
}


const Utility::String& CheckBox::getText() const
{
	return m_text;
}


void CheckBox::setFont(std::weak_ptr<Drawing::Font> font)
{
	m_font = font;
}


void CheckBox::setTextColor(const Color& textColor)
{
	m_textColor = textColor;
}


const Drawing::Color& CheckBox::getTextColor() const
{
	return m_textColor;
}


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

