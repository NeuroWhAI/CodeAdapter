#ifndef __CA__SCROLL_BAR_H__
#define __CA__SCROLL_BAR_H__


#include "BasicDeclaration.h"

#include "Control.h"

#include "Rectangle.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class ScrollBar : public Control
{
private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(RectangleF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	ScrollBar();
	virtual ~ScrollBar();


private:
	f32 m_maxValue;
	f32 m_value;
	bool m_barControlMode;


protected:
	RectangleF m_barRect;
	Color m_barColor;
	f32 m_barThicknessRate;
	f32 m_minBarLength;
	f32 m_barLengthScale;


public:
	ValueFEventHandler WhenValueChanged;


public:
	virtual void onValueChanged(const ValueFEventArgs& args);


protected:
	virtual void onTouchDown(const TouchEventArgs& args) override;

	virtual void onLeaveFocus(const EventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
		const Transform& localTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


protected:
	virtual RectangleF onUpdateScrollBar(const Transform& parentTransform, const PointF& localCursor,
		bool barControlMode) = 0;


public:
	virtual f32 getBarLength() const = 0;


public:
	void setMaxValue(f32 maxValue);
	f32 getMaxValue() const;
	void setValue(f32 value);
	f32 getValue() const;


public:
	void setBarColor(const Color& barColor);
	const Color& getBarColor() const;
	void setBarThicknessRate(f32 rate);
	f32 getBarThicknessRate() const;
	void setMinBarLength(f32 length);
	f32 getMinBarLength() const;
	void setBarLengthScale(f32 scale);
	f32 getBarLengthScale() const;
};


END_NAMESPACE_CA_UI


#endif