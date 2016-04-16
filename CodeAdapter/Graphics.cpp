#include "Graphics.h"

#include "Factory.h"




BEGIN_NAMESPACE_CA_DRAWING


Graphics::Graphics()
	: textArtist(Factory::getInstance()->createTextArtist())
	, rectangleArtist(Factory::getInstance()->createRectangleArtist())
{

}


Graphics::~Graphics()
{

}


END_NAMESPACE_CA_DRAWING

