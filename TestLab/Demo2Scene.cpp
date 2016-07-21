#include "Demo2Scene.h"

#include "Demo3Scene.h"




Demo2Scene::Demo2Scene(const caUtil::ResourcePool& pool)
	: m_pool(pool)
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

	m_font = m_pool.getFont(L"BoldFont");
	if (m_font == nullptr)
	{
		m_font = caFactory->createFont();
		m_font->loadFromFile("NanumGothic.ttf");
		m_font->setCharacterSize(64);
		m_font->setStyle(caDraw::FontStyles::Bold);
	}

	m_texture1 = m_pool.getTexture(L"Logo");
	if (m_texture1 == nullptr)
	{
		m_texture1 = caFactory->createTexture();
		m_texture1->loadFromFile("neurowhai.png");
	}

	m_sprite1 = canew<caDraw::DrawableTexture>();
	m_sprite1->setTexture(m_texture1);
	m_sprite1->location = { 64, 64 };
	m_sprite1->transform.scale = { 0.4f, 0.4f };
	m_sprite1->color = caDraw::Color::Black;

	m_checkboxRed = canew<caUI::CheckBox>();
	m_checkboxRed->setFont(m_font);
	m_checkboxRed->setText("Red");
	m_checkboxRed->setBackColor(caDraw::Color::Transparent);
	m_checkboxRed->setTextMargin({ 4, 0 });
	m_checkboxRed->setPosition({ 500, 110 });
	m_checkboxRed->setSize({ 256, 64 });
	m_checkboxRed->WhenCheckedChanged = [box = m_checkboxRed, img = m_sprite1]
	(const caUI::EventArgs args) {
		img->color.r = (box->isChecked() ? 255 : 0);
	};

	m_checkboxGreen = canew<caUI::CheckBox>(*m_checkboxRed);
	m_checkboxGreen->setText("Green");
	m_checkboxGreen->setPosition({ 500, 110 + 100 });
	m_checkboxGreen->WhenCheckedChanged = [box = m_checkboxGreen, img = m_sprite1]
	(const caUI::EventArgs args) {
		img->color.g = (box->isChecked() ? 255 : 0);
	};

	m_checkboxBlue = canew<caUI::CheckBox>(*m_checkboxRed);
	m_checkboxBlue->setText("Blue");
	m_checkboxBlue->setPosition({ 500, 110 + 100 * 2 });
	m_checkboxBlue->WhenCheckedChanged = [box = m_checkboxBlue, img = m_sprite1]
	(const caUI::EventArgs args) {
		img->color.b = (box->isChecked() ? 255 : 0);
	};

	m_colorRadioGroup = canew<caUI::RadioButtonGroup>();

	m_radioRed = canew<caUI::RadioButton>();
	m_radioRed->setGroup(m_colorRadioGroup);
	m_radioRed->setFont(m_font);
	m_radioRed->setText("RED");
	m_radioRed->setBackColor(caDraw::Color::Transparent);
	m_radioRed->setTextMargin({ 4, 0 });
	m_radioRed->setPosition({ 760, 110 });
	m_radioRed->setSize({ 360, 64 });
	m_radioRed->WhenCheckedChanged =
		[box = m_radioRed, img = m_sprite1, other = m_checkboxRed]
	(const caUI::EventArgs args) {
		img->color = caDraw::Color::Black;
		img->color.r = (box->isChecked() ? 255 : 0);
		other->check(box->isChecked());
	};

	m_radioGreen = canew<caUI::RadioButton>(*m_radioRed);
	m_radioGreen->setText("GREEN");
	m_radioGreen->setPosition({ 760, 110 + 100 });
	m_radioGreen->WhenCheckedChanged =
		[box = m_radioGreen, img = m_sprite1, other = m_checkboxGreen]
	(const caUI::EventArgs args) {
		img->color = caDraw::Color::Black;
		img->color.g = (box->isChecked() ? 255 : 0);
		other->check(box->isChecked());
	};

	m_radioBlue = canew<caUI::RadioButton>(*m_radioRed);
	m_radioBlue->setText("BLUE");
	m_radioBlue->setPosition({ 760, 110 + 100 * 2 });
	m_radioBlue->WhenCheckedChanged = 
		[box = m_radioBlue, img = m_sprite1, other = m_checkboxBlue]
	(const caUI::EventArgs args) {
		img->color = caDraw::Color::Black;
		img->color.b = (box->isChecked() ? 255 : 0);
		other->check(box->isChecked());
	};

	m_colorRadioGroup->add(m_radioRed);
	m_colorRadioGroup->add(m_radioGreen);
	m_colorRadioGroup->add(m_radioBlue);

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

	m_panel->addDrawable(m_radioRed);
	m_panel->addUpdatable(m_radioRed);

	m_panel->addDrawable(m_radioGreen);
	m_panel->addUpdatable(m_radioGreen);

	m_panel->addDrawable(m_radioBlue);
	m_panel->addUpdatable(m_radioBlue);

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

