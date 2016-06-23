#include "Demo2Scene.h"

#include "Demo3Scene.h"




Demo2Scene::Demo2Scene()
{

}


Demo2Scene::~Demo2Scene()
{

}

//###########################################################################

void Demo2Scene::onInitialize(caDraw::Window& owner)
{
	auto winSize = owner.getSize();


	m_panel = caFactory->createPanel();
	m_panel->transform.position = { 0, 0 };
	m_panel->size = static_cast<caDraw::SizeF>(winSize);

	m_font = caFactory->createFont();
	m_font->loadFromFile("NanumGothic.ttf");
	m_font->setCharacterSize(64);
	m_font->setStyle(caDraw::FontStyles::Bold);

	m_texture1 = caFactory->createTexture();
	m_texture1->loadFromFile("neurowhai.png");

	m_sprite1 = canew<caDraw::DrawableTexture>();
	m_sprite1->setTexture(m_texture1);
	m_sprite1->location = { 64, 64 };
	m_sprite1->transform.scale = { 0.4f, 0.4f };

	m_checkboxRed = canew<caUI::CheckBox>();
	m_checkboxRed->setFont(m_font);
	m_checkboxRed->setText("Red");
	m_checkboxRed->check(true);
	m_checkboxRed->setBackColor(caDraw::Color::Transparent);
	m_checkboxRed->setTextMargin({ 4, 0 });
	m_checkboxRed->setPosition({ 550, 110 });
	m_checkboxRed->setSize({ 360, 64 });
	m_checkboxRed->WhenCheckedChanged = [box = m_checkboxRed, img = m_sprite1]
	(const caUI::EventArgs args) {
		img->color.r = (box->isChecked() ? 255 : 0);
	};

	m_checkboxGreen = canew<caUI::CheckBox>(*m_checkboxRed);
	m_checkboxGreen->setText("Green");
	m_checkboxGreen->setPosition({ 550, 110 + 100 });
	m_checkboxGreen->WhenCheckedChanged = [box = m_checkboxGreen, img = m_sprite1]
	(const caUI::EventArgs args) {
		img->color.g = (box->isChecked() ? 255 : 0);
	};

	m_checkboxBlue = canew<caUI::CheckBox>(*m_checkboxRed);
	m_checkboxBlue->setText("Blue");
	m_checkboxBlue->setPosition({ 550, 110 + 100 * 2 });
	m_checkboxBlue->WhenCheckedChanged = [box = m_checkboxBlue, img = m_sprite1]
	(const caUI::EventArgs args) {
		img->color.b = (box->isChecked() ? 255 : 0);
	};

	m_buttonNext = canew<caUI::Button>();
	m_buttonNext->setFont(m_font);
	m_buttonNext->setText(L"Next page");
	m_buttonNext->setBackColor(caDraw::Color::Gray);
	m_buttonNext->setPosition({ static_cast<f32>(winSize.width / 2 - 165), 600 });
	m_buttonNext->setSize({ 330, 100 });
	m_buttonNext->WhenClick = [me = this](const caUI::EventArgs& args)
	{
		me->reserveNextScene<Demo3Scene>();
	};


	m_panel->addDrawable(m_sprite1);

	m_panel->addDrawable(m_checkboxRed);
	m_panel->addUpdatable(m_checkboxRed);

	m_panel->addDrawable(m_checkboxGreen);
	m_panel->addUpdatable(m_checkboxGreen);

	m_panel->addDrawable(m_checkboxBlue);
	m_panel->addUpdatable(m_checkboxBlue);

	m_panel->addDrawable(m_buttonNext);
	m_panel->addUpdatable(m_buttonNext);


	addPanel(m_panel);
}


void Demo2Scene::onRelease()
{

}


void Demo2Scene::onUpdate(caDraw::Window& owner)
{
	
}


void Demo2Scene::onDrawBack(caDraw::Graphics& g)
{

}


void Demo2Scene::onDrawFront(caDraw::Graphics& g)
{

}

