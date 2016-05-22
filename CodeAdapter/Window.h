#ifndef __CA__WINDOW_H__
#define __CA__WINDOW_H__


#include <memory>
#include <vector>

#include "BasicDeclaration.h"

#include "Sharable.h"

#include "WindowEvent.h"




BEGIN_NAMESPACE_CA_DRAWING


class Window : public Utility::Sharable
{
private:
	USING_CA_SYSTEM(WindowEvent);


public:
	using Ptr = std::shared_ptr<Window>;
	using ConstPtr = std::shared_ptr<const Window>;


public:
	Window();
	virtual ~Window();


protected:
	std::shared_ptr<Graphics> m_graphics;
	std::vector<std::shared_ptr<Panel>> m_panelList;


private:
	WindowEvent m_latestEvent;


public:
	virtual void create(const Size& size, const Utility::String& title) = 0;
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
	bool addPanel(std::shared_ptr<Panel> panel);
	bool removePanel(std::shared_ptr<const Panel> panel);


public:
	bool checkLatestEvent(WindowEvent::Types type) const;
	WindowEvent getLatestEvent() const;
};


END_NAMESPACE_CA_DRAWING


#endif