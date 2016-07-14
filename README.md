# Code Adapter
C++ GUI, 2D Graphics  
�ٸ� ���̺귯���� �������̽��� �������Ѽ� ���� �ڵ��� ������ �ִ��� ���� �� �ְ� ���ִ� ���̺귯��.

### Project List
  - Code Adapter : ������Ų �������̽��� �� ���̺귯��.
  - CodeAdapterSFML : SFML ���̺귯���� �������̽��� ������Ų ����.
  - TestLab : �׽�Ʈ �� ���� ������Ʈ.

### Features
  - 2D Graphics
  - GUI
  - Scene System

### To Do / Doing
  - [x] Add more GUI controls.
  - [x] Upgrade demo project.
  - [ ] Network
  - [ ] Audio
  - [ ] System time and date
  - [ ] File stream

### Demo
![](https://cloud.githubusercontent.com/assets/1130686/16357706/0831e87c-3b39-11e6-8cde-315f82a426aa.PNG "")

```c++
/*
* main.cpp
*/


#include <CodeAdapter\EasyCA.h>
#include <CodeAdapterSFML\SFMLFactory.h>

#include "HelloScene.h"




int main()
{
	initializeCA<SFMLFactory>();


	auto window = caFactory->createWindow();
	window->create(caDraw::Size(1024, 768), caUtil::String("Hello, World!"));
	window->setFramerate(60);


	auto sceneManager = canew<caUtil::SceneManager>();
	sceneManager->replaceScene(*window, canew<HelloScene>());

	window->setSceneManager(sceneManager);


	while (window->isRunning())
	{
		caTouch->update();
		caKeyboard->update(*window);


		if (sceneManager->hasScene() == false
			|| caKeyboard->isKeyDown(caSys::Keys::Escape))
		{
			window->exit();
		}


		window->update();
		window->draw(caDraw::Color(230, 230, 230));
	}


	return 0;
}
```

```c++
/*
* HelloScene.h
*/


#ifndef __HELLO_SCENE_H__
#define __HELLO_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class HelloScene : public caUtil::Scene
{
public:
	HelloScene();
	virtual ~HelloScene();


protected:
	std::shared_ptr<caDraw::Panel> m_panel;
	std::shared_ptr<caDraw::Font> m_font;
	std::shared_ptr<caDraw::Font> m_font2;
	std::shared_ptr<caDraw::Font> m_font3;
	std::shared_ptr<caDraw::Texture> m_texLogo;
	std::shared_ptr<caDraw::DrawableTexture> m_sprLogo;
	std::shared_ptr<caUI::Label> m_logo;
	std::shared_ptr<caUI::Label> m_logo2;
	std::shared_ptr<caUI::Label> m_logo3;
	std::shared_ptr<caUI::Button> m_buttonNext;
	std::shared_ptr<caUI::VerticalScrollBar> m_scrollOpacity;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif
```

```c++
/*
* HelloScene.cpp
*/


#include "HelloScene.h"




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

	m_font = caFactory->createFont();
	m_font->loadFromFile("NanumGothic.ttf");
	m_font->setCharacterSize(64);
	m_font->setStyle(caDraw::FontStyles::Bold);

	m_font2 = caFactory->createFont();
	m_font2->loadFromFile("NanumGothic.ttf");
	m_font2->setCharacterSize(64);
	m_font2->setStyle(caDraw::FontStyles::Bold | caDraw::FontStyles::Underline);

	m_font3 = caFactory->createFont();
	m_font3->loadFromFile("NanumGothic.ttf");
	m_font3->setCharacterSize(64);
	m_font3->setStyle(caDraw::FontStyles::StrikeOut | caDraw::FontStyles::Italic);

	m_texLogo = caFactory->createTexture();
	m_texLogo->loadFromFile("neurowhai.png");

	m_sprLogo = canew<caDraw::DrawableTexture>();
	m_sprLogo->setTexture(m_texLogo);
	m_sprLogo->location.setLocation(static_cast<f32>(winSize.width / 2 - 555),
		static_cast<f32>(winSize.height / 2 - 555));

	m_logo = canew<caUI::Label>();
	m_logo->setFont(m_font);
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
	m_buttonNext->WhenClick = [me = this](const caUI::EventArgs& args)
	{
		me->reserveNextScene(nullptr);
	};

	m_scrollOpacity = canew<caUI::VerticalScrollBar>();
	m_scrollOpacity->setPosition({ 0, 0 });
	m_scrollOpacity->setSize({ 24.0f, static_cast<f32>(winSize.height) });
	m_scrollOpacity->setMaxValue(255);
	m_scrollOpacity->setValue(255);
	m_scrollOpacity->setMinBarLength(64);
	m_scrollOpacity->WhenValueChanged = 
		[&logo = m_sprLogo](const caUI::ValueFEventArgs& args)
	{
		logo->color.a = static_cast<i32>(args.value);
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
```