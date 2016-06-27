#include "Demo1Scene.h"

#include "Demo2Scene.h"




Demo1Scene::Demo1Scene(const caUtil::ResourcePool& pool)
	: m_pool(pool)
{

}


Demo1Scene::~Demo1Scene()
{
	
}

//###########################################################################

void Demo1Scene::onInitialize(caDraw::Window& owner)
{
	auto winSize = owner.getSize();


	m_panel = caFactory->createPanel();
	m_panel->transform.position = { 0, 0 };
	m_panel->size = static_cast<caDraw::SizeF>(winSize);

	m_font = caFactory->createFont();
	m_font->loadFromFile("NanumGothic.ttf");
	m_font->setCharacterSize(64);
	m_font->setStyle(caDraw::FontStyles::Bold);

	m_rect1 = canew<caDraw::DrawableRectangle>(32, 64, 256, 128);
	m_rect1->edgeColor = caDraw::Color::Magenta;
	m_rect1->fillColor = caDraw::Color::Yellow;
	m_rect1->edgeWidth = 8.0f;

	m_ellipse1 = canew<caDraw::DrawableEllipse>(-32, -64, 256, 128);
	m_ellipse1->transform.position = { 64, 128 };
	m_ellipse1->edgeColor = caDraw::Color::Yellow;
	m_ellipse1->fillColor = caDraw::Color::Magenta;
	m_ellipse1->edgeWidth = 2.0f;

	m_line1 = canew<caDraw::DrawableLine>(m_rect1->x, m_rect1->y,
		m_rect1->x + m_rect1->width, m_rect1->y + m_rect1->height);
	m_line1->color = caDraw::Color::Cyan;
	m_line1->thickness = 8.0f;

	m_desc = canew<caUI::Label>();
	m_desc->setFont(m_font);
	m_desc->setText(L"Press W, S, A, D Key");
	m_desc->setPosition({ 340, 32 });
	m_desc->setSize({ 300, 48 });
	m_desc->setBackColor(caDraw::Color::Transparent);

	m_buttonNext = canew<caUI::Button>();
	m_buttonNext->setFont(m_font);
	m_buttonNext->setText(L"Next page");
	m_buttonNext->setBackColor(caDraw::Color::Gray);
	m_buttonNext->setPosition({ static_cast<f32>(winSize.width / 2 - 165), 600 });
	m_buttonNext->setSize({ 330, 100 });
	m_buttonNext->WhenClick = [me = this, pool = m_pool](const caUI::EventArgs& args)
	{
		me->reserveNextScene<Demo2Scene>(pool);
	};


	m_panel->addDrawable(m_rect1);

	m_panel->addDrawable(m_ellipse1);

	m_panel->addDrawable(m_line1);

	m_panel->addDrawable(m_desc);
	m_panel->addUpdatable(m_desc);

	m_panel->addDrawable(m_buttonNext);
	m_panel->addUpdatable(m_buttonNext);


	addPanel(m_panel);
}


void Demo1Scene::onRelease()
{

}


void Demo1Scene::onUpdate(caDraw::Window& owner)
{
	if (caKeyboard->isKeyPressed(caSys::Keys::W))
	{
		m_rect1->move(0, -8);

		m_buttonNext->setVisible(false);
	}
	else if (caKeyboard->isKeyPressed(caSys::Keys::S))
	{
		m_rect1->move(0, 8);

		m_buttonNext->setVisible(false);
	}
	else
	{
		m_buttonNext->setVisible(true);
	}

	if (caKeyboard->isKeyPressed(caSys::Keys::A))
	{
		m_rect1->move(-8, 0);

		m_buttonNext->setVisible(false);
	}
	else if (caKeyboard->isKeyPressed(caSys::Keys::D))
	{
		m_rect1->move(8, 0);

		m_buttonNext->setVisible(false);
	}
	else
	{
		m_buttonNext->setVisible(true);
	}


	m_ellipse1->transform.angle += 1.0f;
}


void Demo1Scene::onDrawBack(caDraw::Graphics& g)
{

}


void Demo1Scene::onDrawFront(caDraw::Graphics& g)
{

}

