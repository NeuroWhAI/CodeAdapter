#ifndef __CA__BUTTON_H__
#define __CA__BUTTON_H__


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
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
		const Transform& localTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;
};


END_NAMESPACE_CA_UI


#endif