#ifndef __CA__KEYBOARD_H__
#define __CA__KEYBOARD_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Keys.h"




BEGIN_NAMESPACE_CA_SYSTEM


class Keyboard
{
public:
	Keyboard();
	virtual ~Keyboard();


protected:
	static std::shared_ptr<Keyboard> s_instance;


private:
	class Cleaner
	{
	public:
		virtual ~Cleaner()
		{
			if (s_instance)
			{
				s_instance.reset();
			}
		}
	};

	static Cleaner s_cleaner;


public:
	static Keyboard* getInstance();


public:
	virtual void update() = 0;


public:
	virtual bool isKeyDown(Keys key) const = 0;
	virtual bool isKeyPressed(Keys key) const = 0;
	virtual bool isKeyUp(Keys key) const = 0;
	virtual Keys getLatestDownKey() const = 0;
	virtual Keys getLatestPressedKey() const = 0;
	virtual Keys getLatestUpKey() const = 0;
};


END_NAMESPACE_CA_SYSTEM


#endif