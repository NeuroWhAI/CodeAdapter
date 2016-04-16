#ifndef __CA_SFML__TEXT_ARTIST_H__
#define __CA_SFML__TEXT_ARTIST_H__


#include "CodeAdapter\TextArtist.h"




class TextArtist : public CodeAdapter::Drawing::TextArtist
{
public:
	TextArtist();
	virtual ~TextArtist();
};


#endif