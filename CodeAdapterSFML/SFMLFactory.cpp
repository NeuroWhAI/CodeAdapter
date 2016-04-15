#include "SFMLFactory.h"

#include "Window.h"




SFMLFactory::SFMLFactory()
{

}


SFMLFactory::~SFMLFactory()
{

}

//###########################################################################

std::shared_ptr<CodeAdapter::Drawing::Window> SFMLFactory::createWindow()
{
	return std::make_shared<Window>();
}


std::shared_ptr<CodeAdapter::Drawing::TextArtist> SFMLFactory::createTextArtist()
{
	return nullptr;
}

