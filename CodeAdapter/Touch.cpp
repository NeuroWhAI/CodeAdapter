#include "Touch.h"

#include "Factory.h"




BEGIN_NAMESPACE_CA_SYSTEM


std::shared_ptr<Touch> Touch::s_touchListener = nullptr;
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
	if (s_touchListener == nullptr)
	{
		s_touchListener = Factory::getInstance()->createTouch();
	}


	return s_touchListener.get();
}


END_NAMESPACE_CA_SYSTEM

