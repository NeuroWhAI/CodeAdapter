#ifndef __CA__HORIZONTAL_SCROLL_BAR_H__
#define __CA__HORIZONTAL_SCROLL_BAR_H__


#include "BasicDeclaration.h"

#include "ScrollBar.h"




BEGIN_NAMESPACE_CA_UI


class HorizontalScrollBar : public ScrollBar
{
public:
	using Ptr = std::shared_ptr<HorizontalScrollBar>;


private:
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(RectangleF);
	USING_CA_DRAWING(Transform);


public:
	HorizontalScrollBar();
	virtual ~HorizontalScrollBar();


protected:
	f32 m_cursorOffset;


protected:
	virtual RectangleF onUpdateScrollBar(const Transform& parentTransform, const PointF& localCursor,
		bool barControlMode) override;


public:
	virtual f32 getBarLength() const override;
};


END_NAMESPACE_CA_UI


#endif