#include "Keyboard.h"




Keyboard::Keyboard()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		m_oldKeyMap[i] = false;
		m_currentKeyMap[i] = false;
	}
}


Keyboard::~Keyboard()
{

}

//###########################################################################

void Keyboard::update()
{
	for (int key = 0; key < sf::Keyboard::KeyCount; ++key)
	{
		m_oldKeyMap[key] = m_currentKeyMap[key];
		m_currentKeyMap[key] = sf::Keyboard::isKeyPressed(
			static_cast<sf::Keyboard::Key>(key));
	}
}

//###########################################################################

bool Keyboard::isKeyDown(Keys key) const
{
	sf::Keyboard::Key code = static_cast<sf::Keyboard::Key>(key);

	return (!m_oldKeyMap[code] && m_currentKeyMap[code]);
}


bool Keyboard::isKeyPressed(Keys key) const
{
	sf::Keyboard::Key code = static_cast<sf::Keyboard::Key>(key);

	return (m_oldKeyMap[code] && m_currentKeyMap[code]);
}


bool Keyboard::isKeyUp(Keys key) const
{
	sf::Keyboard::Key code = static_cast<sf::Keyboard::Key>(key);

	return (m_oldKeyMap[code] && !m_currentKeyMap[code]);
}

