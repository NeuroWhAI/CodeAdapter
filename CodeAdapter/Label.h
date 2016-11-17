#ifndef __CA__LABEL_H__
#define __CA__LABEL_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Control.h"

#include "String.h"
#include "Point.h"




BEGIN_NAMESPACE_CA_UI


class Label : public Control
{
public:
	using Ptr = std::shared_ptr<Label>;


private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	Label();
	virtual ~Label();


protected:
	PointF m_textMargin;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
		const Transform& localTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	void setTextMargin(const PointF& margin);
	const PointF& getTextMargin() const;
};


END_NAMESPACE_CA_UI


#endif