#ifndef __CA__KEYBOARD_H__
#define __CA__KEYBOARD_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Keys.h"




BEGIN_NAMESPACE_CA_SYSTEM


class Keyboard
{
private:
	USING_CA_DRAWING(Window);


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


private:
	u32 m_typedUnicode;


public:
	static Keyboard* getInstance();


public:
	void update(Window& win);


protected:
	virtual void onUpdate(Window& win) = 0;

	
public:
	bool getTypedText(u32* outUnicode = nullptr);


public:
	virtual bool isKeyDown(Keys key) const = 0;
	virtual bool isKeyPressed(Keys key) const = 0;
	virtual bool isKeyUp(Keys key) const = 0;
	virtual Keys getDownKey() const = 0;
	virtual Keys getPressedKey() const = 0;
	virtual Keys getUpKey() const = 0;
};


END_NAMESPACE_CA_SYSTEM


#endif