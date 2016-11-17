#ifndef __CA__LIST_BOX_H__
#define __CA__LIST_BOX_H__


#include <memory>
#include <vector>

#include "BasicDeclaration.h"

#include "Control.h"

#include "Point.h"

#include "String.h"




BEGIN_NAMESPACE_CA_UI


class ListBox : public Control
{
public:
	using Ptr = std::shared_ptr<ListBox>;


private:
	USING_CA(i32);

	USING_CA_DRAWING(Point);
	USING_CA_DRAWING(PointF);
	USING_CA_DRAWING(Transform);
	USING_CA_DRAWING(Graphics);

	USING_CA_UTILITY(String);


public:
	ListBox();
	ListBox(const ListBox& right);
	virtual ~ListBox();


protected:
	PointF m_itemMargin;


protected:
	std::vector<String> m_item;


private:
	i32 m_selectedIndex;


protected:
	std::unique_ptr<VerticalScrollBar> m_verticalBar;


public:
	ValueEventHandler WhenSelectedIndexChanged;


public:
	virtual void onSelectedIndexChanged(const ValueEventArgs& args);


protected:
	virtual void onMove(const EventArgs& args) override;

	virtual void onResize(const EventArgs& args) override;

	virtual void onTouchDown(const TouchEventArgs& args) override;


protected:
	virtual void onUpdateControl(const Transform& parentTransform, const PointF& parentCursor,
		const Transform& localTransform, const PointF& localCursor) override;
	virtual void onDrawControl(Graphics& g, const Transform& parentTransform) override;


public:
	ListBox& operator= (const ListBox& right);


public:
	void setItemMargin(const PointF& margin);
	const PointF& getItemMargin() const;


public:
	void addItem(const String& text);
	void insertItem(i32 index, const String& text);
	void removeItem(const String& text);
	void removeItemAt(i32 index);
	i32 itemIndexOf(const String& text) const;
	void clearItems();
	i32 getItemCount() const;
	i32 getItemHeight() const;


public:
	bool hasSelectedItem() const;
	i32 getSelectedIndex() const;
	void selectItemAt(i32 index);
	void deselectItem();


protected:
	void updateScrollBar();
};


END_NAMESPACE_CA_UI


#endif