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
	Color m_overlayColor;
	Color m_focusColor;
	Color m_touchColor;


protected:
	virtual void onTouchDown(const TouchEventArgs& args) override;
	virtual void onTouchUp(const TouchEventArgs& args) override;

	virtual void onEnterFocus(const EventArgs& args) override;
	virtual void onLeaveFocus(const EventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	void setFocusColor(const Color& focusColor);
	const Color& getFocusColor() const;
	void setTouchColor(const Color& touchColor);
	const Color& getTouchColor() const;
};


END_NAMESPACE_CA_UI


#endif