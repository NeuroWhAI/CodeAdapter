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
		// ���ú�ȯ�� ������ȯ�� ��ħ
		Transform combinedTransform = parentTransform;
		combinedTransform.addTransform(transform);


		// Ŀ�� ��ġ ��ȯ
		PointF localCursor = combinedTransform.inverseTransformPoint(static_cast<PointF>(cursor));


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
				// ���õ� �� ������ ���õ� ���� ����
				if (m_canSelected)
				{
					setSelect(true);
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
			// ��Ŀ���� ���� ���� ����
			setFocus(false);

			// ���� Ŭ���ߴٸ�
			if (System::Touch::getInstance()->isDown())
			{
				// ���õ� ���� ����
				setSelect(false);
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

	// ���� ä���
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
			if (WhenEnterFocus)
			{
				WhenEnterFocus(args);
			}
		}
		else
		{
			if (WhenLeaveFocus)
			{
				WhenLeaveFocus(args);
			}
		}
	}
	else
	{
		m_focused = focused;
	}
}


void Control::setSelect(bool selected)
{
	if (m_selected != selected)
	{
		m_selected = selected;

		EventArgs args;

		if (selected)
		{
			if (WhenSelected)
			{
				WhenSelected(args);
			}
		}
		else
		{
			if (WhenDeselected)
			{
				WhenDeselected(args);
			}
		}
	}
	else
	{
		m_selected = selected;
	}
}


END_NAMESPACE_CA_UI

