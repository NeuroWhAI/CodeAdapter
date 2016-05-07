#ifndef __CA__LABEL_H__
#define __CA__LABEL_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Control.h"

#include "String.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class Label : public Control
{
private:
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	Label();
	virtual ~Label();


protected:
	Utility::String m_text;
	std::weak_ptr<Drawing::Font> m_font;
	Color m_textColor;


protected:
	virtual void onUpdateControl(const Transform& parentTransform) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	void setText(const Utility::String& text);
	const Utility::String& getText() const;
	void setFont(std::weak_ptr<Drawing::Font> font);
	void setTextColor(const Color& textColor);
	const Color& getTextColor() const;
};


END_NAMESPACE_CA_UI


#endif