#include "Panel.h"

#include "Graphics.h"




BEGIN_NAMESPACE_CA_DRAWING


Panel::Panel()
	: size(1, 1)
{

}


Panel::~Panel()
{

}

//###########################################################################

void Panel::onDraw(Graphics& g, const Transform& parentTransform)
{
	// ���ú�ȯ�� ������ȯ�� ���ļ� draw�� �μ��� �ѱ�
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

void Panel::update()
{
	
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


END_NAMESPACE_CA_DRAWING

