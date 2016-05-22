#include "Keyboard.h"

#include "Factory.h"

#include "Window.h"




BEGIN_NAMESPACE_CA_SYSTEM


std::shared_ptr<Keyboard> Keyboard::s_instance = nullptr;
Keyboard::Cleaner Keyboard::s_cleaner;

//###########################################################################

Keyboard::Keyboard()
	: m_typedUnicode(0)
{

}


Keyboard::~Keyboard()
{

}

//###########################################################################

Keyboard* Keyboard::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = Factory::getInstance()->createKeyboard();
	}


	return s_instance.get();
}

//###########################################################################

void Keyboard::update(Window& win)
{
	m_typedUnicode = 0;

	// 텍스트가 입력되었으면
	if (win.checkLatestEvent(System::WindowEvent::Types::TextEntered))
	{
		// 입력된 유니코드를 가져옴.
		m_typedUnicode = win.getLatestEvent().text.unicode;
	}


	onUpdate(win);
}

//###########################################################################

bool Keyboard::getTypedText(u32* outUnicode)
{
	if (outUnicode != nullptr)
	{
		*outUnicode = m_typedUnicode;
	}


	return (m_typedUnicode != 0);
}


END_NAMESPACE_CA_SYSTEM

