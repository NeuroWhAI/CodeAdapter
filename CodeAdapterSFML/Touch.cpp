#include "Touch.h"

#include "SFML\Graphics.hpp"

#include "CodeAdapter\UsingSharable.h"

#include "CodeAdapter\SharedObject.h"

#include "CodeAdapter\Point.h"
#include "CodeAdapter\Window.h"




Touch::Touch(SharedObject<sf::RenderWindow>& sharedWin)
	: m_sharedWin(sharedWin)

	, m_oldState(false)
	, m_currentState(false)
	, m_oldLongState(false)
	, m_currentLongState(false)
{

}


Touch::~Touch()
{

}

//###########################################################################

void Touch::update()
{
	// 터치 상태 갱신
	m_oldState = m_currentState;
	m_currentState = sf::Touch::isDown(0)
		|| sf::Mouse::isButtonPressed(sf::Mouse::Left);


	m_oldLongState = m_currentLongState;

	if (isDown())
	{
		m_touchDownTime = system_clock::now();
	}
	else if (isUp())
	{
		m_currentLongState = false;
	}
	else if (isPressed() && !m_currentLongState)
	{
		std::chrono::duration<double> timespan =
			system_clock::now() - m_touchDownTime;

		if (timespan.count() > 1.0)
		{
			m_currentLongState = true;
		}
	}
}

//###########################################################################

bool Touch::isDown() const
{
	return (!m_oldState && m_currentState);
}


bool Touch::isPressed() const
{
	return (m_oldState && m_currentState);
}


bool Touch::isUp() const
{
	return (m_oldState && !m_currentState);
}

//--------------------------------------------------------------------------

bool Touch::isLongDown() const
{
	return (!m_oldLongState && m_currentLongState);
}


bool Touch::isLongPressed() const
{
	return (m_oldLongState && m_currentLongState);
}


bool Touch::isLongUp() const
{
	return (m_oldLongState && !m_currentLongState);
}

//--------------------------------------------------------------------------

Touch::Point Touch::getPosition(Window& win) const
{
	CodeAdapter::Utility::UsingSharable shareWin(win);

	auto cursor = sf::Mouse::getPosition(*m_sharedWin.getObject());

	return Point(cursor.x, cursor.y);
}


Touch::PointF Touch::getPositionF(Window& win) const
{
	CodeAdapter::Utility::UsingSharable shareWin(win);

	auto cursor = sf::Mouse::getPosition(*m_sharedWin.getObject());

	return PointF(static_cast<f32>(cursor.x), static_cast<f32>(cursor.y));
}


void Touch::getPosition(i32* pX, i32* pY, Window& win) const
{
	CodeAdapter::Utility::UsingSharable shareWin(win);

	auto cursor = sf::Mouse::getPosition(*m_sharedWin.getObject());

	*pX = cursor.x;
	*pY = cursor.y;
}


void Touch::getPosition(f32* pX, f32* pY, Window& win) const
{
	CodeAdapter::Utility::UsingSharable shareWin(win);

	auto cursor = sf::Mouse::getPosition(*m_sharedWin.getObject());

	*pX = static_cast<f32>(cursor.x);
	*pY = static_cast<f32>(cursor.y);
}

