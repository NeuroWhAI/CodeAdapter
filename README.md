# Code Adapter

C++ GUI, 2D Graphics  
다른 라이브러리의 인터페이스를 강제시켜서 로직 코드의 변경을 최대한 줄일 수 있게 해주는 라이브러리.

## Project List

* CodeAdapter : 강제시킨 인터페이스가 될 라이브러리.
* CodeAdapterSFML : SFML 라이브러리의 인터페이스를 강제시킨 예제.
* TestLab : 테스트 및 데모 프로젝트.

## Features

* 2D Graphics
* GUI
* Scene System
* Audio

## To Do / Doing

* [x] Add more GUI controls.
* [x] Upgrade demo project.
* [ ] Network
* [x] Audio
* [ ] System time and date
* [ ] File stream

## Demo

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
	window->create(caDraw::Size(1024, 768), caUtil::String("Hello, World!"), false);
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
	caDraw::PanelPtr m_panel;
	caDraw::FontPtr m_font;
	caDraw::FontPtr m_font2;
	caDraw::FontPtr m_font3;
	caDraw::TexturePtr m_texLogo;
	caDraw::DrawableTexturePtr m_sprLogo;
	caUI::LabelPtr m_logo;
	caUI::LabelPtr m_logo2;
	caUI::LabelPtr m_logo3;
	caUI::ButtonPtr m_buttonNext;
	caUI::VerticalScrollBarPtr m_scrollOpacity;


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

	m_panel->addControl(m_logo);
	m_panel->addControl(m_logo2);
	m_panel->addControl(m_logo3);
	m_panel->addControl(m_scrollOpacity);


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
