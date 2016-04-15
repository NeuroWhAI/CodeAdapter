#ifndef __CA__WINDOW_H__
#define __CA__WINDOW_H__


#include <memory>
#include <vector>

#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_UTILITY


class String;


END_NAMESPACE_CA_UTILITY


BEGIN_NAMESPACE_CA_DRAWING


template <typename T>
class PointT;
using Point = PointT<i32>;

template <typename T>
class SizeT;
using Size = SizeT<i32>;

template <typename T>
class ColorT;
using Color = ColorT<i32>;

class Panel;

class Graphics;


class Window
{
public:
	using Ptr = std::shared_ptr<Window>;
	using ConstPtr = std::shared_ptr<const Window>;


public:
	Window();
	virtual ~Window();


protected:
	std::shared_ptr<Graphics> m_graphics;
	std::vector<std::shared_ptr<Panel>> m_panelList;


public:
	virtual void create(const Size& size, const Utility::String& title) = 0;
	virtual void exit() = 0;

	virtual bool isRunning() const = 0;


public:
	virtual void show() = 0;
	virtual void hide() = 0;

	virtual bool isOpen() const = 0;

	
public:
	void update();
	void draw(const Color& backColor);


protected:
	virtual void onUpdate() = 0;
	virtual void beginDraw(const Color& backColor) = 0;
	virtual void endDraw() = 0;


public:
	bool addPanel(std::shared_ptr<Panel> panel);
	bool removePanel(std::shared_ptr<const Panel> panel);
};


END_NAMESPACE_CA_DRAWING


#endif