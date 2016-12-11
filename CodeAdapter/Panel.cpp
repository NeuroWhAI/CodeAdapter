#include "Panel.h"

#include <cmath>

#include "Touch.h"

#include "Graphics.h"

#include "Control.h"




BEGIN_NAMESPACE_CA_DRAWING


Panel::Panel()
	: size(1, 1)
{

}


Panel::~Panel()
{

}

//###########################################################################

void Panel::update(const Transform& parentTransform, const Point& cursor)
{
	// 로컬변환과 전역변환을 합침
	Transform combinedTransform = parentTransform;
	combinedTransform.addTransform(transform);


	// 커서 위치 변환
	Point iLocalCursor = static_cast<Point>(combinedTransform.inverseTransformPoint(static_cast<PointF>(cursor)));


	// 요소 갱신
	for (auto& updatable : m_updatables)
	{
		auto ptr = updatable.lock();
		if (ptr)
		{
			ptr->update(combinedTransform, cursor);
		}
	}
}

//###########################################################################

void Panel::onDraw(Graphics& g, const Transform& parentTransform)
{
	// 로컬변환과 전역변환을 합침
	Transform combinedTransform = parentTransform;
	combinedTransform.addTransform(transform);


	beginDraw(combinedTransform);


	// 요소 그리기
	for (auto& drawable : m_drawables)
	{
		auto ptr = drawable.lock();
		if (ptr)
		{
			ptr->draw(g, combinedTransform);
		}
	}


	endDraw();
}

//###########################################################################

void Panel::setVisible(bool visible)
{
	Drawable::setVisible(visible);


	for (auto& drawable : m_drawables)
	{
		auto ptr = drawable.lock();
		if (ptr)
		{
			ptr->setVisible(visible);
		}
	}
}

//###########################################################################

void Panel::update(Window& win)
{
	// 커서 위치 변환
	PointF cursor = System::Touch::getInstance()->getPositionF(win);
	Point iLocalCursor = static_cast<Point>(cursor);


	// 요소 갱신
	for (auto& updatable : m_updatables)
	{
		auto ptr = updatable.lock();
		if (ptr)
		{
			ptr->update(transform, iLocalCursor);
		}
	}
}


void Panel::draw(Graphics& g)
{
	if (m_visible)
	{
		beginDraw(transform);


		// 요소 그리기
		for (auto& drawable : m_drawables)
		{
			auto ptr = drawable.lock();
			if (ptr)
			{
				ptr->draw(g, transform);


				g.setTransform(Transform::Identity);
			}
		}


		endDraw();
	}
}

//###########################################################################

bool Panel::addDrawable(std::weak_ptr<Drawable> drawable)
{
	return addItemTo(m_drawables, drawable);
}


bool Panel::removeDrawable(std::weak_ptr<const Drawable> drawable)
{
	return removeItemFrom(m_drawables, drawable);
}

//###########################################################################

bool Panel::addUpdatable(std::weak_ptr<Updatable> updatable)
{
	return addItemTo(m_updatables, updatable);
}


bool Panel::removeUpdatable(std::weak_ptr<const Updatable> updatable)
{
	return removeItemFrom(m_updatables, updatable);
}

//###########################################################################

bool Panel::addControl(std::weak_ptr<UI::Control> control)
{
	bool suc1 = addItemTo<Drawable>(m_drawables, control);
	bool suc2 = addItemTo<Updatable>(m_updatables, control);


	return (suc1 || suc2);
}


bool Panel::removeControl(std::weak_ptr<const UI::Control> control)
{
	bool suc1 = removeItemFrom<Drawable>(m_drawables, control);
	bool suc2 = removeItemFrom<Updatable>(m_updatables, control);


	return (suc1 || suc2);
}


END_NAMESPACE_CA_DRAWING

