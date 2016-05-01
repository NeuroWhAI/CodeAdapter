#ifndef __CA__CONTROL_H__
#define __CA__CONTROL_H__


#include "BasicDeclaration.h"

#include "Updatable.h"
#include "Drawable.h"

#include "Size.h"




BEGIN_NAMESPACE_CA_UI


class Control : public Drawing::Updatable, public Drawing::Drawable
{
private:
	USING_CA_DRAWING(SizeF);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	Control();
	virtual ~Control();


public:
	SizeF size;


public:
	virtual void update(const Transform& parentTransform) override;
	
	
protected:
	virtual void onDraw(Graphics& g, const Transform& parentTransform) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform) = 0;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) = 0;
};


END_NAMESPACE_CA_UI


#endif