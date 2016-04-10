#include "Factory.h"

#include "Window.h"




Factory::Factory()
{

}


Factory::~Factory()
{

}

//###########################################################################

std::shared_ptr<CodeAdapter::Drawing::Window> Factory::createWindow()
{
	return std::make_shared<Window>();
}

