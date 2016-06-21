#ifndef __DEMO2_SCENE_H__
#define __DEMO2_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class Demo2Scene : public caUtil::Scene
{
public:
	Demo2Scene();
	virtual ~Demo2Scene();


protected:
	std::shared_ptr<caDraw::Panel> m_panel;
	std::shared_ptr<caDraw::Font> m_font;
	std::shared_ptr<caDraw::Texture> m_texture1;
	std::shared_ptr<caDraw::DrawableTexture> m_sprite1;
	std::shared_ptr<caUI::CheckBox> m_checkboxRed;
	std::shared_ptr<caUI::CheckBox> m_checkboxGreen;
	std::shared_ptr<caUI::CheckBox> m_checkboxBlue;
	std::shared_ptr<caUI::Button> m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDraw(caDraw::Graphics& g) override;
};


#endif