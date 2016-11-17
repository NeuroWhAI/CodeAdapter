#ifndef __CA__PANEL_H__
#define __CA__PANEL_H__


#include <memory>
#include <vector>

#include "BasicDeclaration.h"

#include "Updatable.h"
#include "Drawable.h"

#include "Transform.h"
#include "Size.h"




BEGIN_NAMESPACE_CA_DRAWING


class Panel : public Updatable, public Drawable
{
public:
	using Ptr = std::shared_ptr<Panel>;


public:
	Panel();
	virtual ~Panel();


public:
	SizeF size;


protected:
	std::vector<std::weak_ptr<Updatable>> m_updatables;
	std::vector<std::weak_ptr<Drawable>> m_drawables;


protected:
	virtual void beginDraw(const Transform& parentTransform) = 0;
	virtual void endDraw() = 0;


public:
	virtual void update(const Transform& parentTransform, const Point& cursor) override;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform) override;


public:
	virtual void setVisible(bool visible) override;


public:
	void update(Window& win);
	void draw(Graphics& g);


public:
	bool addDrawable(std::weak_ptr<Drawable> drawable);
	bool removeDrawable(std::weak_ptr<const Drawable> drawable);


public:
	bool addUpdatable(std::weak_ptr<Updatable> updatable);
	bool removeUpdatable(std::weak_ptr<const Updatable> updatable);
};


END_NAMESPACE_CA_DRAWING


#endif