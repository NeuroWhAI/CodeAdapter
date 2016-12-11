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
	caDraw::PanelPtr m_panel;
	caDraw::FontPtr m_font;
	caDraw::TexturePtr m_texture1;
	caDraw::DrawableTexturePtr m_sprite1;
	caUI::CheckBoxPtr m_checkboxRed;
	caUI::CheckBoxPtr m_checkboxGreen;
	caUI::CheckBoxPtr m_checkboxBlue;
	caUI::RadioButtonGroupPtr m_colorRadioGroup;
	caUI::RadioButtonPtr m_radioRed;
	caUI::RadioButtonPtr m_radioGreen;
	caUI::RadioButtonPtr m_radioBlue;
	caUI::ButtonPtr m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif