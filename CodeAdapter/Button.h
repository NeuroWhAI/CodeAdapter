#ifndef __CA__BUTTON_H__
#define __CA__BUTTON_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Control.h"

#include "String.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class Button : public Control
{
private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	Button();
	virtual ~Button();


protected:
	Utility::String m_text;
	std::weak_ptr<Drawing::Font> m_font;
	Color m_textColor;
	Color m_overlayColor;
	Color m_focusColor;
	Color m_touchColor;


private:
	bool m_wasTouchDown;


public:
	EventHandler WhenClick;


public:
	virtual void onClick(const EventArgs& args);


protected:
	virtual void onTouchDown(const TouchEventArgs& args) override;
	virtual void onTouchUp(const TouchEventArgs& args) override;

	virtual void onEnterFocus(const EventArgs& args) override;
	virtual void onLeaveFocus(const EventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	void setText(const Utility::String& text);
	const Utility::String& getText() const;
	void setFont(std::weak_ptr<Drawing::Font> font);
	void setTextColor(const Color& textColor);
	const Color& getTextColor() const;
	void setFocusColor(const Color& focusColor);
	const Color& getFocusColor() const;
	void setTouchColor(const Color& touchColor);
	const Color& getTouchColor() const;
};


END_NAMESPACE_CA_UI


#endif