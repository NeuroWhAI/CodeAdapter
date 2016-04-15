#ifndef __CA__GRAPHICS_H__
#define __CA__GRAPHICS_H__


#include <memory>

#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_DRAWING


class TextArtist;


class Graphics
{
public:
	Graphics();
	virtual ~Graphics();


public:
	std::shared_ptr<TextArtist> textArtist;
};


END_NAMESPACE_CA_DRAWING


#endif