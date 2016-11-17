#ifndef __CA__DRAWABLE_TEXT_H__
#define __CA__DRAWABLE_TEXT_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Drawable.h"

#include "String.h"
#include "Point.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_DRAWING


class DrawableText : public Drawable
{
public:
	using Ptr = std::shared_ptr<DrawableText>;


public:
	DrawableText();
	DrawableText(const Utility::String& text);
	virtual ~DrawableText();


public:
	Utility::String text;
	PointF location;
	Color color;


protected:
	std::weak_ptr<Font> m_font;


protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform);


public:
	void setFont(std::weak_ptr<Font> font);
};


END_NAMESPACE_CA_DRAWING


#endif