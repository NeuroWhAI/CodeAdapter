#include "Graphics.h"

#include "Factory.h"

#include "TextArtist.h"
#include "RectangleArtist.h"
#include "EllipseArtist.h"
#include "LineArtist.h"
#include "TextureArtist.h"




BEGIN_NAMESPACE_CA_DRAWING


Graphics::Graphics()
	: textArtist(Factory::getInstance()->createTextArtist())
	, rectangleArtist(Factory::getInstance()->createRectangleArtist())
	, ellipseArtist(Factory::getInstance()->createEllipseArtist())
	, lineArtist(Factory::getInstance()->createLineArtist())
	, textureArtist(Factory::getInstance()->createTextureArtist())
{

}


Graphics::~Graphics()
{

}

//###########################################################################

void Graphics::setTransform(const Transform& transform)
{
	textArtist->initialize(transform);
	rectangleArtist->initialize(transform);
	ellipseArtist->initialize(transform);
	lineArtist->initialize(transform);
	textureArtist->initialize(transform);
}


const Transform& Graphics::getTransform() const
{
	return textArtist->getTransform();
}


END_NAMESPACE_CA_DRAWING

