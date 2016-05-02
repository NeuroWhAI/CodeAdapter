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
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(SizeF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	Control();
	virtual ~Control();


protected:
	PointF m_position;
	SizeF m_size;
	Color m_backColor;
	bool m_enabled;


public:
	TouchEventHandler WhenTouchDown;
	TouchEventHandler WhenTouchUp;

	KeyEventHandler WhenKeyDown;
	KeyEventHandler WhenKeyUp;


public:
	virtual void update(const Transform& parentTransform) override;
	
	
protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform) = 0;
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
};


END_NAMESPACE_CA_UI


#endif