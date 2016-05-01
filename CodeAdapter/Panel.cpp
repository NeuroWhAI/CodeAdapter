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
	// 로컬변환과 전역변환을 합쳐서 draw의 인수로 넘김
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

void Panel::update()
{
	
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


END_NAMESPACE_CA_DRAWING

