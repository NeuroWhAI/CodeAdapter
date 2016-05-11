#include "Control.h"

#include "Touch.h"

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
			m_focused = true;


			TouchEventArgs touchArgs = {
				static_cast<i32>(localCursor.x),
				static_cast<i32>(localCursor.y)
			};

			// 터치 입력 처리
			if (System::Touch::getInstance()->isDown())
			{
				// 선택될 수 있으면 선택된 상태 설정
				if (m_canSelected)
				{
					m_selected = true;
				}


				if (WhenTouchDown)
				{
					WhenTouchDown(touchArgs);
				}
			}
			else if (System::Touch::getInstance()->isUp())
			{
				if (WhenTouchUp)
				{
					WhenTouchUp(touchArgs);
				}
			}
		}
		else
		{
			// 포커스를 잃은 상태 설정
			m_focused = false;

			// 밖을 클릭했다면
			if (System::Touch::getInstance()->isDown())
			{
				// 선택된 상태 해제
				m_selected = false;
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
		m_focused = false;
		m_selected = false;
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
		m_selected = false;
	}
}


bool Control::isSelected() const
{
	return m_selected;
}


END_NAMESPACE_CA_UI

