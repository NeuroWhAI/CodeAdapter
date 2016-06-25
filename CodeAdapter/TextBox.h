#ifndef __CA__TEXT_BOX_H__
#define __CA__TEXT_BOX_H__


#include <memory>
#include <vector>

#include "BasicDeclaration.h"

#include "Control.h"

#include "String.h"
#include "Point.h"
#include "Color.h"




BEGIN_NAMESPACE_CA_UI


class TextBox : public Control
{
private:
	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Color);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);
	USING_CA_DRAWING(Font);

	USING_CA_UTILITY(String);


public:
	TextBox();
	virtual ~TextBox();


protected:
	PointF m_textMargin;
	bool m_isMultiline;


protected:
	Point m_cursorIndex;
	std::vector<String> m_linedText;
	f32 m_lineSpacing;


protected:
	virtual void onKeyDown(const KeyEventArgs& args) override;

	virtual void onSelected(const EventArgs& args) override;
	virtual void onDeselected(const EventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	virtual void setText(const String& text) override;
	virtual void setFont(std::weak_ptr<Font> font) override;


public:
	void setTextMargin(const PointF& margin);
	const PointF& getTextMargin() const;
	void setMultiline(bool isMultiline);
	bool isMultiline() const noexcept;


protected:
	void syncMyText();
};


END_NAMESPACE_CA_UI


#endif