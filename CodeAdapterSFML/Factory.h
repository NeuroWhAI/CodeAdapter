#ifndef __CA_SFML__FACTORY_H__
#define __CA_SFML__FACTORY_H__


#include "CodeAdapter\Factory.h"




class Factory : public CodeAdapter::Factory
{
public:
	Factory();
	virtual ~Factory();


public:
	virtual std::shared_ptr<CodeAdapter::Drawing::Window> createWindow() override;
};


#endif