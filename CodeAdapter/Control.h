#ifndef __CA__CONTROL_H__
#define __CA__CONTROL_H__


#include <memory>

#include "BasicDeclaration.h"

#include "ControlEvent.h"

#include "Updatable.h"
#include "Drawable.h"

#include "Point.h"
#include "Size.h"
#include "Color.h"
#include "String.h"




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
	USING_CA_DRAWING(Font);

	USING_CA_UTILITY(String);


public:
	explicit Control(bool canSelected);
	virtual ~Control();


protected:
	Color m_backColor;
	Color m_foreColor;
	Color m_focusOverlayColor;
	Color m_touchOverlayColor;
	std::weak_ptr<Font> m_font;


private:
	PointF m_position;
	SizeF m_size;
	bool m_enabled;
	bool m_focused;
	bool m_canSelected;
	bool m_selected;
	String m_text;


private:
	bool m_wasTouchDown;
	Color m_overlayColor;


public:
	EventHandler WhenMove;

	EventHandler WhenResize;

	TouchEventHandler WhenClick;

	TouchEventHandler WhenTouchDown;
	TouchEventHandler WhenTouchUp;

	KeyEventHandler WhenKeyDown;
	KeyEventHandler WhenKeyUp;

	EventHandler WhenEnterFocus;
	EventHandler WhenLeaveFocus;

	EventHandler WhenSelected;
	EventHandler WhenDeselected;

	EventHandler WhenTextChanged;


public:
	virtual void onMove(const EventArgs& args);

	virtual void onResize(const EventArgs& args);

	virtual void onClick(const TouchEventArgs& args);

	virtual void onTouchDown(const TouchEventArgs& args);
	virtual void onTouchUp(const TouchEventArgs& args);

	virtual void onKeyDown(const KeyEventArgs& args);
	virtual void onKeyUp(const KeyEventArgs& args);

	virtual void onEnterFocus(const EventArgs& args);
	virtual void onLeaveFocus(const EventArgs& args);

	virtual void onSelected(const EventArgs& args);
	virtual void onDeselected(const EventArgs& args);

	virtual void onTextChanged(const EventArgs& args);


public:
	virtual void update(const Transform& parentTransform, const Point& cursor) override;
	
	
protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) = 0;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) = 0;


public:
	virtual void setVisible(bool visible) override;
	const PointF& getPosition() const noexcept;
	void setPosition(const PointF& position);
	const SizeF& getSize() const noexcept;
	void setSize(const SizeF& size);
	const Color& getBackColor() const noexcept;
	void setBackColor(const Color& backColor);
	const Color& getForeColor() const noexcept;
	void setForeColor(const Color& foreColor);
	const Color& getFocusColor() const noexcept;
	void setFocusColor(const Color& focusColor);
	const Color& getTouchColor() const noexcept;
	void setTouchColor(const Color& touchColor);
	const String& getText() const noexcept;
	virtual void setText(const String& text);
	void setFont(std::weak_ptr<Font> font);
	bool isEnabled() const noexcept;
	void setEnabled(bool enabled);
	bool isFocused() const noexcept;
	bool canSelected() const noexcept;
	void setSelectable(bool canSelected);
	bool isSelected() const noexcept;


protected:
	void setFocus(bool focused);
	void setSelect(bool selected);
	String& getMyText() noexcept;
	const Color& getOverlayColor() const noexcept;
	void setOverlayColor(const Color& overlayColor);
};


END_NAMESPACE_CA_UI


#endif