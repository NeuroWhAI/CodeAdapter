#ifndef __CA_SFML__FACTORY_H__
#define __CA_SFML__FACTORY_H__


#include "CodeAdapter\Factory.h"




class SFMLFactory : public CodeAdapter::Factory
{
public:
	SFMLFactory();
	virtual ~SFMLFactory();


public:
	virtual std::shared_ptr<CodeAdapter::Drawing::Window> createWindow() override;
	virtual std::shared_ptr<CodeAdapter::Drawing::TextArtist> createTextArtist() override;
};


#endif