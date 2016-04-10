#ifndef __CA_SFML__WINDOW_H__
#define __CA_SFML__WINDOW_H__


#include "CodeAdapter\Window.h"

#include "SFML\Graphics.hpp"




class Window : public CodeAdapter::Drawing::Window
{
public:
	using Size = CodeAdapter::Drawing::Size;
	using Color = CodeAdapter::Drawing::Color;
	using String = CodeAdapter::Utility::String;


public:
	Window();
	virtual ~Window();


protected:
	sf::RenderWindow m_win;


public:
	virtual void create(const Size& size, const String& title) override;
	virtual void exit() override;

	virtual bool isRunning() const override;


public:
	virtual void show() override;
	virtual void hide() override;

	virtual bool isOpen() const override;


protected:
	virtual void onUpdate() override;
	virtual void beginDraw(const Color& backColor) override;
	virtual void endDraw() override;
};


#endif