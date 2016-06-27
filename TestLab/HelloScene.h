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