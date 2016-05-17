#include "Button.h"

#include "Transform.h"
#include "Graphics.h"

#include "TextArtist.h"
#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


Button::Button()
	: Control(false)

	, m_text("")
	, m_textColor(Color::Black)
	, m_overlayColor(Color::Transparent)
	, m_focusColor(Color(Color::Cyan, 64))
	, m_touchColor(Color(Color::Cyan, 128))

	, m_wasTouchDown(false)
{

}


Button::~Button()
{

}

//###########################################################################

void Button::onClick(const EventArgs& args)
{
	if (WhenClick)
	{
		WhenClick(args);
	}
}

//###########################################################################

void Button::onTouchDown(const TouchEventArgs& args)
{
	Control::onTouchDown(args);


	// ��ư�� ������ �������� �Ǵ��ϱ� ���� �÷���
	m_wasTouchDown = true;


	m_overlayColor = m_touchColor;
}


void Button::onTouchUp(const TouchEventArgs& args)
{
	Control::onTouchUp(args);


	m_overlayColor = m_focusColor;


	// ��ư�� ������ ���Ŷ��
	if (m_wasTouchDown)
	{
		// ��ư Ŭ�� �̺�Ʈ �߻�
		onClick(static_cast<const EventArgs&>(args));


		// ��ư ���� �÷��� ����
		m_wasTouchDown = false;
	}
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


	// ��Ŀ���� ������ ��ư ���� �÷��� ����
	m_wasTouchDown = false;


	m_overlayColor = Color::Transparent;
}

//###########################################################################

void Button::onUpdateControl(const Transform& parentTransform, const PointF& localCursor)
{
	// Empty
}


void Button::onDrawControl(Graphics& g, const Transform& parentTransform)
{
	// ��� �׸���
	auto& rectArtist = g.rectangleArtist;
	rectArtist->initialize(parentTransform);

	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(m_position, m_size, m_overlayColor);
	rectArtist->endFillRectangle();


	// �ؽ�Ʈ �׸���
	if (!m_font.expired())
	{
		auto& artist = g.textArtist;


		artist->initialize(parentTransform);


		artist->beginDrawString(*m_font.lock());

		artist->drawString(m_text,
			m_position.x + m_size.width / 2.0f,
			m_position.y + m_size.height / 2.0f,
			m_textColor,
			Drawing::TextAligns::Center);

		artist->endDrawString();
	}
}

//###########################################################################

void Button::setText(const Utility::String& text)
{
	m_text = text;
}


const Utility::String& Button::getText() const
{
	return m_text;
}


void Button::setFont(std::weak_ptr<Drawing::Font> font)
{
	m_font = font;
}


void Button::setTextColor(const Color& textColor)
{
	m_textColor = textColor;
}


const Drawing::Color& Button::getTextColor() const
{
	return m_textColor;
}


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

