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


protected:
	caAudio::SoundPtr m_bgm;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif