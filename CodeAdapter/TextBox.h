#ifndef __CA__TEXT_BOX_H__
#define __CA__TEXT_BOX_H__


#include <memory>

#include "BasicDeclaration.h"

#include "Control.h"

#include "String.h"
#include "Point.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class TextBox : public Control
{
private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);


public:
	TextBox();
	virtual ~TextBox();


protected:
	PointF m_textMargin;


protected:
	i32 m_cursorIndex;


protected:
	virtual void onKeyDown(const KeyEventArgs& args) override;

	virtual void onSelected(const EventArgs& args) override;
	virtual void onDeselected(const EventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	void setTextMargin(const PointF& margin);
	const PointF& getTextMargin() const;
};


END_NAMESPACE_CA_UI


#endif