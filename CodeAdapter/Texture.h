#ifndef __CA__TEXTURE_H__
#define __CA__TEXTURE_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_DRAWING


class Texture
{
public:
	Texture();
	virtual ~Texture();


public:
	virtual bool loadFromFile(const Utility::String& filename) = 0;
	virtual bool loadFromFile(const Utility::String& filename,
		const Rectangle& rectangle) = 0;


public:
	virtual void attachToGraphics() = 0;
};


END_NAMESPACE_CA_DRAWING


#endif