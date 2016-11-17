#ifndef __HELLO_SCENE_H__
#define __HELLO_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class HelloScene : public caUtil::Scene
{
public:
	HelloScene();
	virtual ~HelloScene();


protected:
	caUtil::ResourcePool m_pool;


protected:
	caDraw::Panel::Ptr m_panel;
	caDraw::Font::Ptr m_font;
	caDraw::Font::Ptr m_font2;
	caDraw::Font::Ptr m_font3;
	caDraw::Texture::Ptr m_texLogo;
	caDraw::DrawableTexture::Ptr m_sprLogo;
	caUI::Label::Ptr m_logo;
	caUI::Label::Ptr m_logo2;
	caUI::Label::Ptr m_logo3;
	caUI::Button::Ptr m_buttonNext;
	caUI::VerticalScrollBar::Ptr m_scrollOpacity;


protected:
	caAudio::Sound::Ptr m_bgm;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif