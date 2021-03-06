#include "Touch.h"

#include "Factory.h"




BEGIN_NAMESPACE_CA_SYSTEM


std::shared_ptr<Touch> Touch::s_instance = nullptr;
Touch::Cleaner Touch::s_cleaner;

//###########################################################################

Touch::Touch()
{

}


Touch::~Touch()
{

}

//###########################################################################

Touch* Touch::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = Factory::getInstance()->createTouch();
	}


	return s_instance.get();
}


END_NAMESPACE_CA_SYSTEM

