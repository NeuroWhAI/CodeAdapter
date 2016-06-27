#include "HelloScene.h"

#include "Demo1Scene.h"




HelloScene::HelloScene()
{
	
}


HelloScene::~HelloScene()
{
	
}

//###########################################################################

void HelloScene::onInitialize(caDraw::Window& owner)
{
	auto winSize = owner.getSize();


	m_panel = caFactory->createPanel();
	m_panel->transform.position = { 0, 0 };
	m_panel->size = static_cast<caDraw::SizeF>(winSize);

	m_font = m_pool.createFont(L"BoldFont");
	m_font->loadFromFile("NanumGothic.ttf");
	m_font->setCharacterSize(64);
	m_font->setStyle(caDraw::FontStyles::Bold);

	m_font2 = m_pool.createFont(L"BoldLineFont");
	m_font2->loadFromFile("NanumGothic.ttf");
	m_font2->setCharacterSize(64);
	m_font2->setStyle(caDraw::FontStyles::Bold | caDraw::FontStyles::Underline);

	m_font3 = m_pool.createFont(L"StrikeItalicFont");
	m_font3->loadFromFile("NanumGothic.ttf");
	m_font3->setCharacterSize(64);
	m_font3->setStyle(caDraw::FontStyles::StrikeOut | caDraw::FontStyles::Italic);

	m_texLogo = m_pool.createTexture(L"Logo");
	m_texLogo->loadFromFile("neurowhai.png");

	m_sprLogo = canew<caDraw::DrawableTexture>();
	m_sprLogo->setTexture(m_pool.getTexture(L"Logo"));
	m_sprLogo->location.setLocation(static_cast<f32>(winSize.width / 2 - 555),
		static_cast<f32>(winSize.height / 2 - 555));

	m_logo = canew<caUI::Label>();
	m_logo->setFont(m_pool.getFont(L"BoldFont"));
	m_logo->setText(L"NeuroWhAI");
	m_logo->setTextMargin({ 8, 0 });
	m_logo->setBackColor(caDraw::Color::Transparent);
	m_logo->setPosition({ 128, 164 });
	m_logo->setSize({ 330, 128 });

	m_logo2 = canew<caUI::Label>(*m_logo);
	m_logo2->setFont(m_font2);
	m_logo2->setPosition({ 128, 164 + 70 });

	m_logo3 = canew<caUI::Label>(*m_logo);
	m_logo3->setFont(m_font3);
	m_logo3->setPosition({ 128, 164 + 70 * 2 });

	m_buttonNext = canew<caUI::Button>();
	m_buttonNext->setFont(m_font);
	m_buttonNext->setText(L"Next page");
	m_buttonNext->setBackColor(caDraw::Color::Gray);
	m_buttonNext->setPosition({ static_cast<f32>(winSize.width / 2 - 165), 600 });
	m_buttonNext->setSize({ 330, 100 });
	m_buttonNext->WhenClick = [me = this, pool = m_pool](const caUI::EventArgs& args)
	{
		me->reserveNextScene<Demo1Scene>(pool);
	};

	m_scrollOpacity = canew<caUI::VerticalScrollBar>();
	m_scrollOpacity->setPosition({ 0, 0 });
	m_scrollOpacity->setSize({ 24.0f, static_cast<f32>(winSize.height) });
	m_scrollOpacity->setMaxValue(255);
	m_scrollOpacity->setValue(255);
	m_scrollOpacity->setMinBarLength(64);
	m_scrollOpacity->WhenValueChanged = 
		[&logo = m_sprLogo, &bar = m_scrollOpacity](const caUI::EventArgs& args)
	{
		logo->color.a = static_cast<i32>(bar->getValue());
	};


	m_panel->addDrawable(m_sprLogo);

	m_panel->addDrawable(m_logo);
	m_panel->addUpdatable(m_logo);

	m_panel->addDrawable(m_logo2);
	m_panel->addUpdatable(m_logo2);

	m_panel->addDrawable(m_logo3);
	m_panel->addUpdatable(m_logo3);

	m_panel->addDrawable(m_buttonNext);
	m_panel->addUpdatable(m_buttonNext);

	m_panel->addDrawable(m_scrollOpacity);
	m_panel->addUpdatable(m_scrollOpacity);


	addPanel(m_panel);
}


void HelloScene::onRelease()
{

}


void HelloScene::onUpdate(caDraw::Window& owner)
{
	
}


void HelloScene::onDrawBack(caDraw::Graphics& g)
{

}


void HelloScene::onDrawFront(caDraw::Graphics& g)
{

}

