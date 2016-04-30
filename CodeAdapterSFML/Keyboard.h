#ifndef __CA_SFML__KEYBOARD_H__
#define __CA_SFML__KEYBOARD_H__


#include "CodeAdapter\Keyboard.h"

#include "SFML\Window.hpp"




class Keyboard : public CodeAdapter::System::Keyboard
{
private:
	USING_CA_SYSTEM(Keys);


public:
	Keyboard();
	virtual ~Keyboard();


protected:
	bool m_oldKeyMap[sf::Keyboard::KeyCount];
	bool m_currentKeyMap[sf::Keyboard::KeyCount];


public:
	virtual void update() override;


public:
	virtual bool isKeyDown(Keys key) const override;
	virtual bool isKeyPressed(Keys key) const override;
	virtual bool isKeyUp(Keys key) const override;
};


#endif