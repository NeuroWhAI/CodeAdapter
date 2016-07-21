#ifndef __DEMO2_SCENE_H__
#define __DEMO2_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class Demo2Scene : public caUtil::Scene
{
public:
	explicit Demo2Scene(const caUtil::ResourcePool& pool);
	virtual ~Demo2Scene();


protected:
	caUtil::ResourcePool m_pool;


protected:
	std::shared_ptr<caDraw::Panel> m_panel;
	std::shared_ptr<caDraw::Font> m_font;
	std::shared_ptr<caDraw::Texture> m_texture1;
	std::shared_ptr<caDraw::DrawableTexture> m_sprite1;
	std::shared_ptr<caUI::CheckBox> m_checkboxRed;
	std::shared_ptr<caUI::CheckBox> m_checkboxGreen;
	std::shared_ptr<caUI::CheckBox> m_checkboxBlue;
	std::shared_ptr<caUI::RadioButtonGroup> m_colorRadioGroup;
	std::shared_ptr<caUI::RadioButton> m_radioRed;
	std::shared_ptr<caUI::RadioButton> m_radioGreen;
	std::shared_ptr<caUI::RadioButton> m_radioBlue;
	std::shared_ptr<caUI::Button> m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif