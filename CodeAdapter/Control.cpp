#include "Control.h"

#include "Touch.h"
#include "Keyboard.h"

#include "Transform.h"
#include "Graphics.h"

#include "RectangleArtist.h"




BEGIN_NAMESPACE_CA_UI


Control::Control(bool canSelected)
	: m_position(0, 0)
	, m_size(1, 1)
	, m_backColor(Color::Transparent)
	, m_enabled(true)
	, m_focused(false)
	, m_canSelected(canSelected)
	, m_selected(false)
{

}


Control::~Control()
{

}

//###########################################################################

void Control::onTouchDown(const TouchEventArgs& args)
{
	if (WhenTouchDown)
	{
		WhenTouchDown(args);
	}
}


void Control::onTouchUp(const TouchEventArgs& args)
{
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
	if (WhenEnterFocus)
	{
		WhenEnterFocus(args);
	}
}


void Control::onLeaveFocus(const EventArgs& args)
{
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

//###########################################################################

void Control::update(const Transform& parentTransform, const Point& cursor)
{
	if (m_enabled)
	{
		// 로컬변환과 전역변환을 합침
		Transform combinedTransform = parentTransform;
		combinedTransform.addTransform(transform);


		// 커서 위치 변환
		PointF localCursor = combinedTransform.inverseTransformPoint(static_cast<PointF>(cursor));


		// 커서가 컨트롤 영역안에 들어와있다면
		if (localCursor.x > m_position.x
			&& localCursor.x < m_position.x + m_size.width
			&& localCursor.y > m_position.y
			&& localCursor.y < m_position.y + m_size.height)
		{
			// 포커스 상태 설정
			setFocus(true);


			TouchEventArgs touchArgs = {
				static_cast<i32>(localCursor.x),
				static_cast<i32>(localCursor.y)
			};

			// 터치 입력 처리
			if (System::Touch::getInstance()->isDown())
			{
				// 선택될 수 있으면 선택된 상태 설정
				setSelect(true);


				onTouchDown(touchArgs);
			}
			else if (System::Touch::getInstance()->isUp())
			{
				onTouchUp(touchArgs);
			}
		}
		else
		{
			// 포커스를 잃은 상태 설정
			setFocus(false);

			// 밖을 클릭했다면
			if (System::Touch::getInstance()->isDown())
			{
				// 선택된 상태 해제
				setSelect(false);
			}
		}


		if (isSelected())
		{
			auto keyboard = System::Keyboard::getInstance();

			KeyEventArgs keyArgs;

			auto downKey = keyboard->getLatestDownKey();
			auto upKey = keyboard->getLatestUpKey();

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
	}


	onUpdateControl(parentTransform);
}

//###########################################################################

void Control::onDraw(Graphics& g, const Transform& parentTransform)
{
	auto& rectArtist = g.rectangleArtist;
	rectArtist->transform = parentTransform;

	// 배경색 채우기
	rectArtist->beginFillRectangle();
	rectArtist->fillRectangle(m_position, m_size, m_backColor);
	rectArtist->endFillRectangle();


	onDrawControl(g, parentTransform);
}

//###########################################################################

const Drawing::PointF& Control::getPosition() const
{
	return m_position;
}


void Control::setPosition(const PointF& position)
{
	m_position = position;
}


const Drawing::SizeF& Control::getSize() const
{
	return m_size;
}


void Control::setSize(const SizeF& size)
{
	m_size = size;
}


const Drawing::Color& Control::getBackColor() const
{
	return m_backColor;
}


void Control::setBackColor(const Color& backColor)
{
	m_backColor = backColor;
}


bool Control::isEnabled() const
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


bool Control::isFocused() const
{
	return m_focused;
}


bool Control::canSelected() const
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


bool Control::isSelected() const
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
	// 새롭게 설정될 선택 상태가 이전과 다르고
	// 선택된 상태로 설정될때 선택 가능하도록 설정되어 있거나
	// 선택해제된 상태로 설정될때
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


END_NAMESPACE_CA_UI

