#ifndef __CA_SFML__SFML_ARTIST_H__
#define __CA_SFML__SFML_ARTIST_H__


#include "CodeAdapter\Artist.h"

#include "SFML\Graphics.hpp"




class SFMLArtist
{
public:
	SFMLArtist();
	virtual ~SFMLArtist();


protected:
	sf::RenderStates m_renderStates;


protected:
	void updateRenderTransform(const CodeAdapter::Drawing::Transform& transform);
};


#endif