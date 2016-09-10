#ifndef __CA_SFML__WINDOW_H__
#define __CA_SFML__WINDOW_H__


#include "CodeAdapter\Window.h"

#include "SFML\Graphics.hpp"




class Window : public CodeAdapter::Drawing::Window
{
private:
	USING_CA_UTILITY(String);
	USING_CA_UTILITY_T(SharedObject, T);

	USING_CA_DRAWING(Size);
	USING_CA_DRAWING(Color);

	USING_CA_SYSTEM(WindowEvent);


public:
	explicit Window(SharedObject<sf::RenderWindow>& sharedWin);
	virtual ~Window();


protected:
	sf::RenderWindow m_win;
	SharedObject<sf::RenderWindow>& m_sharedWin;


public:
	virtual void create(const Size& size, const String& title, bool isFullscreen) override;
	virtual void exit() override;

	virtual bool isRunning() const override;


public:
	virtual void show() override;
	virtual void hide() override;

	virtual bool isOpen() const override;


protected:
	virtual bool onUpdate(WindowEvent* outEvent) override;
	virtual void beginDraw(const Color& backColor) override;
	virtual void endDraw() override;


public:
	virtual Size getSize() const override;
	virtual void setFramerate(int framePerSec) override;
	virtual void disableFramerate() override;


public:
	virtual void attach() override;
	virtual void detach() override;
};


#endif