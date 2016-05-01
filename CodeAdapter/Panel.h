#ifndef __CA__PANEL_H__
#define __CA__PANEL_H__


#include <memory>
#include <vector>

#include "BasicDeclaration.h"

#include "Transform.h"
#include "Size.h"

#include "Drawable.h"




BEGIN_NAMESPACE_CA_DRAWING


class Panel : public Drawable
{
public:
	Panel();
	virtual ~Panel();


public:
	SizeF size;


protected:
	std::vector<std::weak_ptr<Drawable>> m_drawables;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform);


protected:
	virtual void beginDraw(const Transform& parentTransform) = 0;
	virtual void endDraw() = 0;


public:
	void update();
	void draw(Graphics& g);


public:
	bool addDrawable(std::weak_ptr<Drawable> drawable);
	bool removeDrawable(std::weak_ptr<const Drawable> drawable);
};


END_NAMESPACE_CA_DRAWING


#endif