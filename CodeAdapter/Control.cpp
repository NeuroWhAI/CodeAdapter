#include "Control.h"

#include "Touch.h"
#include "Keyboard.h"

#include "Transform.h"
#include "Graphics.h"

#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


Control::Control(bool canSelected)
	: m_backColor(Color::Transparent)
	, m_foreColor(Color::Black)
	, m_focusOverlayColor(Color(Color::Cyan, 64))
	, m_touchOverlayColor(Color(Color::Cyan, 128))

	, m_position(0, 0)
	, m_size(16, 16)
	, m_enabled(true)
	, m_focused(false)
	, m_canSelected(canSelected)
	, m_selected(false)
	, m_text(L"")

	, m_wasTouchDown(false)
	, m_overlayColor(Color::Transparent)
{

}


Control::~Control()
{

}

//###########################################################################

void Control::onMove(const EventArgs& args)
{
	if (WhenMove)
	{
		WhenMove(args);
	}
}

//--------------------------------------------------------------------------

void Control::onResize(const EventArgs& args)
{
	if (WhenResize)
	{
		WhenResize(args);
	}
}

//--------------------------------------------------------------------------

void Control::onClick(const TouchEventArgs& args)
{
	if (WhenClick)
	{
		WhenClick(args);
	}
}

//--------------------------------------------------------------------------

void Control::onTouchDown(const TouchEventArgs& args)
{
	// ���õ� �� ������ ���õ� ���� ����
	setSelect(true);


	// ��Ʈ���� ������ �������� �Ǵ��ϱ� ���� �÷���
	m_wasTouchDown = true;


	// ���� ����
	setOverlayColor(m_touchOverlayColor);


	// �̺�Ʈ �߻�
	if (WhenTouchDown)
	{
		WhenTouchDown(args);
	}
}


void Control::onTouchUp(const TouchEventArgs& args)
{
	// ��Ʈ���� ������ ���Ŷ��
	if (m_wasTouchDown)
	{
		// Ŭ�� �̺�Ʈ �߻�
		onClick(args);


		// ��Ʈ�� ���� �÷��� ����
		m_wasTouchDown = false;
	}


	// ���� ����
	setOverlayColor(m_focusOverlayColor);


	// �̺�Ʈ �߻�
	if (WhenTouchUp)
	{
		WhenTouchUp(args);
	}
}

//--------------------------------------------------------------------------

void Control::onKeyDown(const KeyEventArgs& args)
{
	if (WhenKeyDown)
	{
		WhenKeyDown(args);
	}
}


void Control::onKeyUp(const KeyEventArgs& args)
{
	if (WhenKeyUp)
	{
		WhenKeyUp(args);
	}
}

//--------------------------------------------------------------------------

void Control::onEnterFocus(const EventArgs& args)
{
	// ���� ����
	setOverlayColor(m_focusOverlayColor);


	// �̺�Ʈ �߻�
	if (WhenEnterFocus)
	{
		WhenEnterFocus(args);
	}
}


void Control::onLeaveFocus(const EventArgs& args)
{
	// ��Ŀ���� ������ ��Ʈ�� ���� �÷��� ����
	m_wasTouchDown = false;


	// ���� ����ȭ
	setOverlayColor(Color::Transparent);


	// �̺�Ʈ �߻�
	if (WhenLeaveFocus)
	{
		WhenLeaveFocus(args);
	}
}

//--------------------------------------------------------------------------

void Control::onSelected(const EventArgs& args)
{
	if (WhenSelected)
	{
		WhenSelected(args);
	}
}


void Control::onDeselected(const EventArgs& args)
{
	if (WhenDeselected)
	{
		WhenDeselected(args);
	}
}

//--------------------------------------------------------------------------

void Control::onTextChanged(const EventArgs& args)
{
	if (WhenTextChanged)
	{
		WhenTextChanged(args);
	}
}

//###########################################################################

void Control::update(const Transform& parentTransform, const Point& cursor)
{
	// ���ú�ȯ�� ������ȯ�� ��ħ
	Transform combinedTransform = parentTransform;
	combinedTransform.addTransform(transform);


	// Ŀ�� ��ġ ��ȯ
	PointF localCursor = combinedTransform.inverseTransformPoint(static_cast<PointF>(cursor));


	if (m_enabled && m_visible)
	{
		// Ŀ���� ��Ʈ�� �����ȿ� �����ִٸ�
		if (localCursor.x > m_position.x
			&& localCursor.x < m_position.x + m_size.width
			&& localCursor.y > m_position.y
			&& localCursor.y < m_position.y + m_size.height)
		{
			// ��Ŀ�� ���� ����
			setFocus(true);


			TouchEventArgs touchArgs = {
				static_cast<i32>(localCursor.x),
				static_cast<i32>(localCursor.y)
			};

			// ��ġ �Է� ó��
			if (System::Touch::getInstance()->isDown())
			{
				onTouchDown(touchArgs);
			}
			else if (System::Touch::getInstance()->isUp())
			{
				onTouchUp(touchArgs);
			}
		}
		else
		{
			// ��Ŀ���� ���� ���� ����
			setFocus(false);

			// ���� Ŭ���ߴٸ�
			if (System::Touch::getInstance()->isDown())
			{
				// ���õ� ���� ����
				setSelect(false);
			}
		}


		// ���õ� ���¶��
		if (isSelected())
		{
			auto keyboard = System::Keyboard::getInstance();

			KeyEventArgs keyArgs;

			auto downKey = keyboard->getDownKey();
			auto upKey = keyboard->getUpKey();

			if (downKey != System::Keys::Unknown
				|| upKey != System::Keys::Unknown)
			{
				keyArgs.ctrl = keyboard->isKeyDown(System::Keys::LControl)
					|| keyboard->isKeyPressed(System::Keys::LControl);
				keyArgs.shift = keyboard->isKeyDown(System::Keys::LShift)
					|| keyboard->isKeyPressed(System::Keys::LShift);
				keyArgs.alt = keyboard->isKeyDown(System::Keys::LAlt)
					|| keyboard->isKeyPressed(System::Keys::LAlt);
			}

			if (downKey != System::Keys::Unknown)
			{
				keyArgs.key = downKey;

				onKeyDown(keyArgs);
			}

			if (upKey != System::Keys::Unknown)
			{
				keyArgs.key = upKey;

				onKeyUp(keyArgs);
			}
		}
	} // if (m_enabled && m_visible)


	onUpdateControl(parentTransform, static_cast<PointF>(cursor),
		combinedTransform, localCursor);
}

//###########################################################################

void Control::onDraw(Graphics& g, const Transform& parentTransform)
{
	auto& rectArtist = g.rectangleArtist;


	// ���� ä���
	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(m_position, m_size, m_backColor);
	rectArtist->endFillRectangle();


	onDrawControl(g, parentTransform);
}

//###########################################################################

void Control::setVisible(bool visible)
{
	Drawable::setVisible(visible);

	if (visible == false)
	{
		setFocus(false);
		setSelect(false);
	}
}


const Drawing::PointF& Control::getPosition() const noexcept
{
	return m_position;
}


void Control::setPosition(const PointF& position)
{
	if (m_position != position)
	{
		m_position = position;


		EventArgs args;
		onMove(args);
	}
}


const Drawing::SizeF& Control::getSize() const noexcept
{
	return m_size;
}


void Control::setSize(const SizeF& size)
{
	if (m_size != size)
	{
		m_size = size;


		EventArgs args;
		onResize(args);
	}
}


const Drawing::Color& Control::getBackColor() const noexcept
{
	return m_backColor;
}


void Control::setBackColor(const Color& backColor)
{
	m_backColor = backColor;
}


auto Control::getForeColor() const noexcept -> const Color&
{
	return m_foreColor;
}


void Control::setForeColor(const Color& foreColor)
{
	m_foreColor = foreColor;
}


const Drawing::Color& Control::getFocusColor() const noexcept
{
	return m_focusOverlayColor;
}


void Control::setFocusColor(const Color& focusColor)
{
	m_focusOverlayColor = focusColor;
}


const Drawing::Color& Control::getTouchColor() const noexcept
{
	return m_touchOverlayColor;
}


void Control::setTouchColor(const Color& touchColor)
{
	m_touchOverlayColor = touchColor;
}


auto Control::getText() const noexcept -> const String&
{
	return m_text;
}


void Control::setText(const String& text)
{
	if (m_text != text)
	{
		m_text = text;


		EventArgs args;
		onTextChanged(args);
	}
}


void Control::setFont(std::weak_ptr<Font> font)
{
	m_font = font;
}


bool Control::isEnabled() const noexcept
{
	return m_enabled;
}


void Control::setEnabled(bool enabled)
{
	m_enabled = enabled;

	if (enabled == false)
	{
		setFocus(false);
		setSelect(false);
	}
}


bool Control::isFocused() const noexcept
{
	return m_focused;
}


bool Control::canSelected() const noexcept
{
	return m_canSelected;
}


void Control::setSelectable(bool canSelected)
{
	m_canSelected = canSelected;

	if (canSelected == false)
	{
		setSelect(false);
	}
}


bool Control::isSelected() const noexcept
{
	return m_selected;
}

//###########################################################################

void Control::setFocus(bool focused)
{
	if (m_focused != focused)
	{
		m_focused = focused;

		EventArgs args;

		if (focused)
		{
			onEnterFocus(args);
		}
		else
		{
			onLeaveFocus(args);
		}
	}
}


void Control::setSelect(bool selected)
{
	// ���Ӱ� ������ ���� ���°� ������ �ٸ���
	// ���õ� ���·� �����ɶ� ���� �����ϵ��� �����Ǿ� �ְų�
	// ���������� ���·� �����ɶ�
	if (m_selected != selected
		&& ((selected && m_canSelected) || !selected))
	{
		m_selected = selected;

		EventArgs args;

		if (selected)
		{
			onSelected(args);
		}
		else
		{
			onDeselected(args);
		}
	}
}


auto Control::getMyText() noexcept -> String&
{
	return m_text;
}

//###########################################################################

auto Control::getOverlayColor() const noexcept -> const Color&
{
	return m_overlayColor;
}


void Control::setOverlayColor(const Color& overlayColor)
{
	m_overlayColor = overlayColor;
}


END_NAMESPACE_CA_UI

