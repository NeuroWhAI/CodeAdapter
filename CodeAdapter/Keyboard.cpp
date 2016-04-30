#include "Keyboard.h"

#include "Factory.h"




BEGIN_NAMESPACE_CA_SYSTEM


std::shared_ptr<Keyboard> Keyboard::s_instance = nullptr;
Keyboard::Cleaner Keyboard::s_cleaner;

//###########################################################################

Keyboard::Keyboard()
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


END_NAMESPACE_CA_SYSTEM

