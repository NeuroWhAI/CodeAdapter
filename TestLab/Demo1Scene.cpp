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


	auto smallFont = m_pool.createFont(L"SmallFont");
	smallFont->loadFromFile("NanumGothic.ttf");
	smallFont->setCharacterSize(18);
	smallFont->setStyle(caDraw::FontStyles::Bold);

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

	m_progress = canew<caUI::ProgressBar>();
	m_progress->setFont(smallFont);
	m_progress->setPosition({ 0, static_cast<f32>(winSize.height) - 32 });
	m_progress->setSize({ static_cast<f32>(winSize.width), 32 });
	m_progress->setBackColor(caDraw::Color::Gray);
	m_progress->setMinValue(0);
	m_progress->setMaxValue(100);
	m_progress->setValue(0);
	m_progress->setText("Move!");
	m_progress->WhenMaxValue = [button = &m_buttonNext](const caUI::ValueFEventArgs& args)
	{
		(*button)->setVisible(true);
	};
	m_progress->WhenMinValue = [button = &m_buttonNext](const caUI::ValueFEventArgs& args)
	{
		(*button)->setVisible(false);
	};

	m_buttonNext = canew<caUI::Button>();
	m_buttonNext->setFont(m_font);
	m_buttonNext->setText(L"Next page");
	m_buttonNext->setBackColor(caDraw::Color::Gray);
	m_buttonNext->setPosition({ static_cast<f32>(winSize.width / 2 - 165), 600 });
	m_buttonNext->setSize({ 330, 100 });
	m_buttonNext->setVisible(false);
	m_buttonNext->WhenClick = [me = this, pool = m_pool](const caUI::EventArgs& args)
	{
		me->reserveNextScene<Demo2Scene>(pool);
	};


	m_panel->addDrawable(m_rect1);
	m_panel->addDrawable(m_ellipse1);
	m_panel->addDrawable(m_line1);

	m_panel->addControl(m_desc);
	m_panel->addControl(m_progress);
	m_panel->addControl(m_buttonNext);


	addPanel(m_panel);
}


void Demo1Scene::onRelease()
{

}


void Demo1Scene::onUpdate(caDraw::Window& owner)
{
	m_progress->addValue(-0.05f);


	if (caKeyboard->isKeyPressed(caSys::Keys::W))
	{
		m_rect1->move(0, -8);

		m_progress->addValue(1);
	}
	else if (caKeyboard->isKeyPressed(caSys::Keys::S))
	{
		m_rect1->move(0, 8);

		m_progress->addValue(1);
	}

	if (caKeyboard->isKeyPressed(caSys::Keys::A))
	{
		m_rect1->move(-8, 0);

		m_progress->addValue(1);
	}
	else if (caKeyboard->isKeyPressed(caSys::Keys::D))
	{
		m_rect1->move(8, 0);

		m_progress->addValue(1);
	}


	m_ellipse1->transform.angle += 1.0f;
}


void Demo1Scene::onDrawBack(caDraw::Graphics& g)
{

}


void Demo1Scene::onDrawFront(caDraw::Graphics& g)
{

}

