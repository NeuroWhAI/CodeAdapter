#ifndef __CA__WINDOW_H__
#define __CA__WINDOW_H__


#include "BasicDeclaration.h"

#include "Sharable.h"

#include "WindowEvent.h"




BEGIN_NAMESPACE_CA_DRAWING


class Window : public Utility::Sharable
{
private:
	USING_CA_DRAWING(Size);

	USING_CA_SYSTEM(WindowEvent);

	USING_CA_UTILITY(SceneManager);


public:
	Window();
	virtual ~Window();


protected:
	std::shared_ptr<Graphics> m_graphics;
	std::shared_ptr<SceneManager> m_sceneManager;


private:
	WindowEvent m_latestEvent;


public:
	virtual void create(const Size& size, const Utility::String& title, bool isFullscreen) = 0;
	virtual void exit() = 0;

	virtual bool isRunning() const = 0;


public:
	virtual void show() = 0;
	virtual void hide() = 0;

	virtual bool isOpen() const = 0;

	
public:
	bool update(WindowEvent* outEvent = nullptr);
	void draw(const Color& backColor);


protected:
	virtual bool onUpdate(WindowEvent* outEvent) = 0;
	virtual void beginDraw(const Color& backColor) = 0;
	virtual void endDraw() = 0;


public:
	void setSceneManager(std::shared_ptr<SceneManager> mgr);


public:
	bool checkLatestEvent(WindowEvent::Types type) const;
	WindowEvent getLatestEvent() const;


public:
	virtual Size getSize() const = 0;
	virtual void setFramerate(int framePerSec) = 0;
	virtual void disableFramerate() = 0;
};


END_NAMESPACE_CA_DRAWING


#endif