#include "Demo4Scene.h"




Demo4Scene::Demo4Scene()
{

}


Demo4Scene::~Demo4Scene()
{

}

//###########################################################################

void Demo4Scene::onInitialize(caDraw::Window& owner)
{
	auto winSize = owner.getSize();


	m_panel = caFactory->createPanel();
	m_panel->transform.position = { 0, 0 };
	m_panel->size = static_cast<caDraw::SizeF>(winSize);

	m_font = caFactory->createFont();
	m_font->loadFromFile("NanumGothic.ttf");
	m_font->setCharacterSize(64);
	m_font->setStyle(caDraw::FontStyles::Bold);

	m_smallFont = caFactory->createFont();
	m_smallFont->loadFromFile("NanumGothic.ttf");
	m_smallFont->setCharacterSize(18);

	m_panelListBox = caFactory->createPanel();
	m_panelListBox->transform.position = { 32, 32 };
	m_panelListBox->size = { 512, 300 };

	m_listBox = canew<caUI::ListBox>();
	m_listBox->setFont(m_smallFont);
	m_listBox->setBackColor(caDraw::Color::White);
	m_listBox->setSize(m_panelListBox->size);
	m_listBox->setItemMargin({ 4, 32 });

	m_textBox = canew<caUI::TextBox>();
	m_textBox->setFont(m_smallFont);
	m_textBox->setTextMargin({ 4, 6 });
	m_textBox->setBackColor(caDraw::Color::Silver);
	m_textBox->setPosition({ 32, 350 });
	m_textBox->setSize({ 400, 32 });

	m_buttonAdd = canew<caUI::Button>();
	m_buttonAdd->setFont(m_smallFont);
	m_buttonAdd->setText(L"Add");
	m_buttonAdd->setBackColor(caDraw::Color::Gray);
	m_buttonAdd->setPosition({ 448, 350 });
	m_buttonAdd->setSize({ 96, 32 });
	m_buttonAdd->WhenClick = [&textBox = m_textBox, &listBox = m_listBox]
	(const caUI::EventArgs& args)
	{
		auto& text = textBox->getText();

		if (text.getLength() > 0)
		{
			listBox->addItem(text);
			textBox->setText(L"");
		}
	};

	m_buttonNext = canew<caUI::Button>();
	m_buttonNext->setFont(m_font);
	m_buttonNext->setText(L"Exit");
	m_buttonNext->setBackColor(caDraw::Color::Gray);
	m_buttonNext->setPosition({ static_cast<f32>(winSize.width / 2 - 165), 600 });
	m_buttonNext->setSize({ 330, 100 });
	m_buttonNext->WhenClick = [me = this](const caUI::EventArgs& args)
	{
		me->reserveNextScene(nullptr);
	};


	m_panelListBox->addControl(m_listBox);

	m_panel->addControl(m_textBox);
	m_panel->addControl(m_buttonAdd);
	m_panel->addControl(m_buttonNext);


	addPanel(m_panel);
	addPanel(m_panelListBox);
}


void Demo4Scene::onRelease()
{

}


void Demo4Scene::onUpdate(caDraw::Window& owner)
{

}


void Demo4Scene::onDrawBack(caDraw::Graphics& g)
{

}


void Demo4Scene::onDrawFront(caDraw::Graphics& g)
{

}

