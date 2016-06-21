#ifndef __CA__CHECK_BOX_H__
#define __CA__CHECK_BOX_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Control.h"

#include "String.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class CheckBox : public Control
{
private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(SizeF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	CheckBox();
	virtual ~CheckBox();


protected:
	PointF m_textMargin;


private:
	bool m_bChecked;
	f32 m_boxRate;
	f32 m_boxThickness;
	f32 m_innerBoxRate;
	Color m_boxColor;
	Color m_backBoxColor;


public:
	EventHandler WhenCheckedChanged;


public:
	virtual void onCheckedChanged(const EventArgs& args);


protected:
	virtual void onClick(const TouchEventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	void setTextMargin(const PointF& margin);
	const PointF& getTextMargin() const;
	void setBoxColor(const Color& boxColor);
	const Color& getBoxColor() const;
	void setBackBoxColor(const Color& backBoxColor);
	const Color& getBackBoxColor() const;
	void setBoxScale(f32 scale) noexcept;
	f32 getBoxScale() const noexcept;
	void setBoxThickness(f32 thickness) noexcept;
	f32 getBoxThickness() const noexcept;
	void setInnerBoxScale(f32 scale) noexcept;
	f32 getInnerBoxScale() const noexcept;
	void check(bool bChecked);
	void toggle();
	bool isChecked() const noexcept;
};


END_NAMESPACE_CA_UI


#endif