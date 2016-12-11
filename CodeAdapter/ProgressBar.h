#ifndef __CA__PROGRESS_BAR_H__
#define __CA__PROGRESS_BAR_H__


#include "BasicDeclaration.h"

#include "Control.h"

#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class ProgressBar : public Control
{
private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(SizeF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	ProgressBar();
	virtual ~ProgressBar();


private:
	f32 m_value;
	f32 m_minValue, m_maxValue;


protected:
	Color m_barColor;


public:
	ValueFEventHandler WhenMaxValue;
	ValueFEventHandler WhenMinValue;


public:
	virtual void onMaxValue(const ValueFEventArgs& args);
	virtual void onMinValue(const ValueFEventArgs& args);


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
		const Transform& localTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	f32 getValue() const noexcept;
	void setValue(f32 value);
	void addValue(f32 delta);
	f32 getMinValue() const noexcept;
	void setMinValue(f32 minValue);
	f32 getMaxValue() const noexcept;
	void setMaxValue(f32 maxValue);
	const Color& getBarColor() const noexcept;
	void setBarColor(const Color& barColor);
};


END_NAMESPACE_CA_UI


#endif