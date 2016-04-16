#ifndef __CA_SFML__WINDOW_H__
#define __CA_SFML__WINDOW_H__


#include "CodeAdapter\Window.h"

#include "SFML\Graphics.hpp"




BEGIN_NAMESPACE_CA_UTILITY


template <typename T>
class SharedObject;


END_NAMESPACE_CA_UTILITY


class Window : public CodeAdapter::Drawing::Window
{
public:
	template <typename T>
	using SharedObject = CodeAdapter::Utility::SharedObject<T>;

	using Size = CodeAdapter::Drawing::Size;
	using Color = CodeAdapter::Drawing::Color;
	using String = CodeAdapter::Utility::String;


public:
	Window(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~Window();


protected:
	sf::RenderWindow m_win;
	SharedObject<sf::RenderWindow>& m_sharedWin;


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