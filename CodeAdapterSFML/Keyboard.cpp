#include "Keyboard.h"

#include "CodeAdapter\Window.h"




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

void Keyboard::onUpdate(Window& win)
{
	m_latestDownKey = Keys::Unknown;
	m_latestPressedKey = Keys::Unknown;
	m_latestUpKey = Keys::Unknown;


	for (int key = 0; key < sf::Keyboard::KeyCount; ++key)
	{
		m_oldKeyMap[key] = m_currentKeyMap[key];
		m_currentKeyMap[key] = sf::Keyboard::isKeyPressed(
			static_cast<sf::Keyboard::Key>(key));


		Keys caKey = static_cast<Keys>(key);

		if (isKeyPressed(caKey))
			m_latestPressedKey = caKey;
		else if (isKeyUp(caKey))
			m_latestUpKey = caKey;
		else if (isKeyDown(caKey))
			m_latestDownKey = caKey;
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


Keyboard::Keys Keyboard::getDownKey() const
{
	return m_latestDownKey;
}


Keyboard::Keys Keyboard::getPressedKey() const
{
	return m_latestPressedKey;
}


Keyboard::Keys Keyboard::getUpKey() const
{
	return m_latestUpKey;
}



