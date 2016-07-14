#ifndef __CA_SFML__PANEL_H__
#define __CA_SFML__PANEL_H__


#include "CodeAdapter\Panel.h"

#include "SFML/Graphics.hpp"




class Panel : public CodeAdapter::Drawing::Panel
{
private:
	USING_CA_DRAWING(Transform);

	USING_CA_UTILITY_T(SharedObject, T);


public:
	explicit Panel(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~Panel();


protected:
	SharedObject<sf::RenderWindow>& m_sharedWin;
	sf::View m_view;


protected:
	virtual void beginDraw(const Transform& parentTransform) override;
	virtual void endDraw() override;
};


#endif