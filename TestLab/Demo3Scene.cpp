#include "Demo3Scene.h"

#include <random>




Demo3Scene::Demo3Scene()
	: m_effectColor(caDraw::Color(caDraw::Color::Black, 200))
{
	
}


Demo3Scene::~Demo3Scene()
{

}

//###########################################################################

void Demo3Scene::onInitialize(caDraw::Window& owner)
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
	m_smallFont->setCharacterSize(24);
	m_smallFont->setStyle(caDraw::FontStyles::Bold);

	m_textbox = canew<caUI::TextBox>();
	m_textbox->setFont(m_font);
	m_textbox->setText(L"*");
	m_textbox->setTextMargin({ 8, 0 });
	m_textbox->setBackColor(caDraw::Color::Silver);
	m_textbox->setPosition({ 64, 64 });
	m_textbox->setSize({ 512, 100 });

	m_textboxRed = canew<caUI::TextBox>();
	m_textboxRed->setFont(m_font);
	m_textboxRed->setText(L"0");
	m_textboxRed->setTextMargin({ 8, 0 });
	m_textboxRed->setBackColor(caDraw::Color(128, 0, 0));
	m_textboxRed->setPosition({ 64, 200 });
	m_textboxRed->setSize({ 256, 100 });
	m_textboxRed->WhenTextChanged = [me = this, box = m_textboxRed]
	(const caUI::EventArgs args) {
		const auto& text = box->getText();
		try
		{
			if(text.getLength() <= 3)
				me->setEffectColorRed(std::stoi(text.getWStr()));
		}
		catch (std::invalid_argument)
		{

		}
	};

	m_textboxGreen = canew<caUI::TextBox>(*m_textboxRed);
	m_textboxGreen->setBackColor(caDraw::Color(0, 128, 0));
	m_textboxGreen->setPosition({ 64 + 280, 200 });
	m_textboxGreen->WhenTextChanged = [me = this, box = m_textboxGreen]
	(const caUI::EventArgs args) {
		const auto& text = box->getText();
		try
		{
			if (text.getLength() <= 3)
				me->setEffectColorGreen(std::stoi(text.getWStr()));
		}
		catch (std::invalid_argument)
		{

		}
	};

	m_textboxBlue = canew<caUI::TextBox>(*m_textboxRed);
	m_textboxBlue->setBackColor(caDraw::Color(0, 0, 128));
	m_textboxBlue->setPosition({ 64 + 280 * 2, 200 });
	m_textboxBlue->WhenTextChanged = [me = this, box = m_textboxBlue]
	(const caUI::EventArgs args) {
		const auto& text = box->getText();
		try
		{
			if (text.getLength() <= 3)
				me->setEffectColorBlue(std::stoi(text.getWStr()));
		}
		catch (std::invalid_argument)
		{

		}
	};

	m_textboxNote = canew<caUI::TextBox>();
	m_textboxNote->setMultiline(true);
	m_textboxNote->setFont(m_smallFont);
	m_textboxNote->setText(L"This is textbox.\n\nHello?\nWorld!");
	m_textboxNote->setBackColor(caDraw::Color::Silver);
	m_textboxNote->setTextMargin({ 8, 0 });
	m_textboxNote->setPosition({ 64, 332 });
	m_textboxNote->setSize({ 512, 256 });

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


	m_panel->addDrawable(m_textbox);
	m_panel->addUpdatable(m_textbox);

	m_panel->addDrawable(m_textboxRed);
	m_panel->addUpdatable(m_textboxRed);

	m_panel->addDrawable(m_textboxGreen);
	m_panel->addUpdatable(m_textboxGreen);

	m_panel->addDrawable(m_textboxBlue);
	m_panel->addUpdatable(m_textboxBlue);

	m_panel->addDrawable(m_textboxNote);
	m_panel->addUpdatable(m_textboxNote);

	m_panel->addDrawable(m_buttonNext);
	m_panel->addUpdatable(m_buttonNext);


	addPanel(m_panel);


	std::mt19937 engine;
	std::uniform_int_distribution<> dist(-32, 32);

	for (f32 x = -64; x < winSize.width + 64; x += 128)
	{
		for (f32 y = -64; y < winSize.height + 64; y += 128)
		{
			m_dotList.emplace_back(x + dist(engine), y + dist(engine));
		}
	}
}


void Demo3Scene::onRelease()
{

}


void Demo3Scene::onUpdate(caDraw::Window& owner)
{
	auto winSize = owner.getSize();


	f32 xSpeed = winSize.width / 2 - caTouch->getPositionF(owner).x;
	xSpeed *= -0.01f;

	for (auto& dot : m_dotList)
	{
		dot.move(xSpeed, 2);

		if (dot.x < -64)
			dot.x = static_cast<f32>(winSize.width + 64);
		else if (dot.x > winSize.width + 64)
			dot.x = -64;

		if (dot.y < -64)
			dot.y = static_cast<f32>(winSize.height + 64);
		else if (dot.y > winSize.height + 64)
			dot.y = -64;
	}
}


void Demo3Scene::onDrawBack(caDraw::Graphics& g)
{
	drawEffect(g, 0, 2);
}


void Demo3Scene::onDrawFront(caDraw::Graphics& g)
{
	drawEffect(g, 1, 2);
}

//###########################################################################

void Demo3Scene::drawEffect(caDraw::Graphics& g, i32 start, i32 skip)
{
	auto& textArtist = g.textArtist;


	auto text = m_textbox->getText();

	i32 index = start;


	textArtist->beginDrawString(*m_font);

	for (const auto& dot : m_dotList)
	{
		if (index % skip == 0)
		{
			textArtist->drawString(text, dot,
				m_effectColor,
				caDraw::TextAligns::Center);
		}


		++index;
	}

	textArtist->endDrawString();
}

//###########################################################################

void Demo3Scene::setEffectColorRed(i32 red)
{
	setColor(m_effectColor.r, red);
}


void Demo3Scene::setEffectColorGreen(i32 green)
{
	setColor(m_effectColor.g, green);
}


void Demo3Scene::setEffectColorBlue(i32 blue)
{
	setColor(m_effectColor.b, blue);
}

//###########################################################################

void Demo3Scene::setColor(i32& var, i32 color)
{
	if (color < 0)
		color = 0;
	else if (color > 255)
		color = 255;

	var = color;
}

