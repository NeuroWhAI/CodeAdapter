#include "Panel.h"

#include <cmath>

#include "Graphics.h"

#include "Touch.h"




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
		updatable.lock()->update(combinedTransform, cursor);
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
		drawable.lock()->draw(g, combinedTransform);
	}


	endDraw();
}

//###########################################################################

void Panel::update(Window& win)
{
	// 커서 위치 변환
	PointF cursor = System::Touch::getInstance()->getPositionF(win);
	Point iLocalCursor = static_cast<Point>(transform.inverseTransformPoint(cursor));


	// 요소 갱신
	for (auto& updatable : m_updatables)
	{
		updatable.lock()->update(transform, iLocalCursor);
	}
}


void Panel::draw(Graphics& g)
{
	beginDraw(transform);


	// 요소 그리기
	for (auto& drawable : m_drawables)
	{
		drawable.lock()->draw(g, transform);
	}


	endDraw();
}

//###########################################################################

bool Panel::addDrawable(std::weak_ptr<Drawable> drawable)
{
	// 중복 확인
	auto target = drawable.lock();

	for (const auto& item : m_drawables)
	{
		if (target == item.lock())
		{
			// 중복
			return false;
		}
	}

	// 중복 아님


	m_drawables.emplace_back(drawable);


	return true;
}


bool Panel::removeDrawable(std::weak_ptr<const Drawable> drawable)
{
	// 존재 확인
	auto target = drawable.lock();

	usize index = 0;
	for (const auto& item : m_drawables)
	{
		// 존재
		if (target == item.lock())
		{
			// 삭제
			m_drawables.erase(m_drawables.begin() + index);
			
			return true;
		}

		++index;
	}

	// 존재 안함


	return false;
}

//###########################################################################

bool Panel::addUpdatable(std::weak_ptr<Updatable> updatable)
{
	// 중복 확인
	auto target = updatable.lock();

	for (const auto& item : m_updatables)
	{
		if (target == item.lock())
		{
			// 중복
			return false;
		}
	}

	// 중복 아님


	m_updatables.emplace_back(updatable);


	return true;
}


bool Panel::removeUpdatable(std::weak_ptr<const Updatable> updatable)
{
	// 존재 확인
	auto target = updatable.lock();

	usize index = 0;
	for (const auto& item : m_updatables)
	{
		// 존재
		if (target == item.lock())
		{
			// 삭제
			m_updatables.erase(m_updatables.begin() + index);

			return true;
		}

		++index;
	}

	// 존재 안함


	return false;
}


END_NAMESPACE_CA_DRAWING

