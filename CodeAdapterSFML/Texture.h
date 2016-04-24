#ifndef __CA_SFML__TEXTURE_H__
#define __CA_SFML__TEXTURE_H__


#include "CodeAdapter\Texture.h"

#include "SFML\Graphics.hpp"




class Texture : public CodeAdapter::Drawing::Texture
{
private:
	USING_CA_UTILITY(String);
	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Rectangle);


public:
	explicit Texture(SharedObject<sf::Texture>& sharedTexture);
	virtual ~Texture();


protected:
	sf::Texture m_texture;
	SharedObject<sf::Texture>& m_sharedTexture;


public:
	virtual bool loadFromFile(const String& filename) override;
	virtual bool loadFromFile(const String& filename,
		const Rectangle& rectangle) override;


public:
	virtual void attachToGraphics() override;
};


#endif