#ifndef __CA__CONTROL_H__
#define __CA__CONTROL_H__


#include "BasicDeclaration.h"

#include "ControlEvent.h"

#include "Updatable.h"
#include "Drawable.h"

#include "Point.h"
#include "Size.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class Control : public Drawing::Updatable, public Drawing::Drawable
{
private:
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(SizeF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	explicit Control(bool canSelected);
	virtual ~Control();


protected:
	PointF m_position;
	SizeF m_size;
	Color m_backColor;


private:
	bool m_enabled;
	bool m_focused;
	bool m_canSelected;
	bool m_selected;


public:
	TouchEventHandler WhenTouchDown;
	TouchEventHandler WhenTouchUp;

	KeyEventHandler WhenKeyDown;
	KeyEventHandler WhenKeyUp;

	EventHandler WhenEnterFocus;
	EventHandler WhenLeaveFocus;

	EventHandler WhenSelected;
	EventHandler WhenDeselected;


public:
	virtual void onTouchDown(const TouchEventArgs& args);
	virtual void onTouchUp(const TouchEventArgs& args);

	virtual void onKeyDown(const KeyEventArgs& args);
	virtual void onKeyUp(const KeyEventArgs& args);

	virtual void onEnterFocus(const EventArgs& args);
	virtual void onLeaveFocus(const EventArgs& args);

	virtual void onSelected(const EventArgs& args);
	virtual void onDeselected(const EventArgs& args);


public:
	virtual void update(const Transform& parentTransform, const Point& cursor) override;
	
	
protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) = 0;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) = 0;


public:
	const PointF& getPosition() const;
	void setPosition(const PointF& position);
	const SizeF& getSize() const;
	void setSize(const SizeF& size);
	const Color& getBackColor() const;
	void setBackColor(const Color& backColor);
	bool isEnabled() const;
	void setEnabled(bool enabled);
	bool isFocused() const;
	bool canSelected() const;
	void setSelectable(bool canSelected);
	bool isSelected() const;


protected:
	void setFocus(bool focused);
	void setSelect(bool selected);
};


END_NAMESPACE_CA_UI


#endif