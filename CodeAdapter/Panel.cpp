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
	// ���ú�ȯ�� ������ȯ�� ��ħ
	Transform combinedTransform = parentTransform;
	combinedTransform.addTransform(transform);


	// Ŀ�� ��ġ ��ȯ
	Point iLocalCursor = static_cast<Point>(combinedTransform.inverseTransformPoint(static_cast<PointF>(cursor)));


	// ��� ����
	for (auto& updatable : m_updatables)
	{
		updatable.lock()->update(combinedTransform, cursor);
	}
}

//###########################################################################

void Panel::onDraw(Graphics& g, const Transform& parentTransform)
{
	// ���ú�ȯ�� ������ȯ�� ��ħ
	Transform combinedTransform = parentTransform;
	combinedTransform.addTransform(transform);


	beginDraw(combinedTransform);


	// ��� �׸���
	for (auto& drawable : m_drawables)
	{
		drawable.lock()->draw(g, combinedTransform);
	}


	endDraw();
}

//###########################################################################

void Panel::update(Window& win)
{
	// Ŀ�� ��ġ ��ȯ
	PointF cursor = System::Touch::getInstance()->getPositionF(win);
	Point iLocalCursor = static_cast<Point>(transform.inverseTransformPoint(cursor));


	// ��� ����
	for (auto& updatable : m_updatables)
	{
		updatable.lock()->update(transform, iLocalCursor);
	}
}


void Panel::draw(Graphics& g)
{
	beginDraw(transform);


	// ��� �׸���
	for (auto& drawable : m_drawables)
	{
		drawable.lock()->draw(g, transform);
	}


	endDraw();
}

//###########################################################################

bool Panel::addDrawable(std::weak_ptr<Drawable> drawable)
{
	// �ߺ� Ȯ��
	auto target = drawable.lock();

	for (const auto& item : m_drawables)
	{
		if (target == item.lock())
		{
			// �ߺ�
			return false;
		}
	}

	// �ߺ� �ƴ�


	m_drawables.emplace_back(drawable);


	return true;
}


bool Panel::removeDrawable(std::weak_ptr<const Drawable> drawable)
{
	// ���� Ȯ��
	auto target = drawable.lock();

	usize index = 0;
	for (const auto& item : m_drawables)
	{
		// ����
		if (target == item.lock())
		{
			// ����
			m_drawables.erase(m_drawables.begin() + index);
			
			return true;
		}

		++index;
	}

	// ���� ����


	return false;
}

//###########################################################################

bool Panel::addUpdatable(std::weak_ptr<Updatable> updatable)
{
	// �ߺ� Ȯ��
	auto target = updatable.lock();

	for (const auto& item : m_updatables)
	{
		if (target == item.lock())
		{
			// �ߺ�
			return false;
		}
	}

	// �ߺ� �ƴ�


	m_updatables.emplace_back(updatable);


	return true;
}


bool Panel::removeUpdatable(std::weak_ptr<const Updatable> updatable)
{
	// ���� Ȯ��
	auto target = updatable.lock();

	usize index = 0;
	for (const auto& item : m_updatables)
	{
		// ����
		if (target == item.lock())
		{
			// ����
			m_updatables.erase(m_updatables.begin() + index);

			return true;
		}

		++index;
	}

	// ���� ����


	return false;
}


END_NAMESPACE_CA_DRAWING

