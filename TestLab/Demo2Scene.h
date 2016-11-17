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
	caDraw::Panel::Ptr m_panel;
	caDraw::Font::Ptr m_font;
	caDraw::Texture::Ptr m_texture1;
	caDraw::DrawableTexture::Ptr m_sprite1;
	caUI::CheckBox::Ptr m_checkboxRed;
	caUI::CheckBox::Ptr m_checkboxGreen;
	caUI::CheckBox::Ptr m_checkboxBlue;
	caUI::RadioButtonGroup::Ptr m_colorRadioGroup;
	caUI::RadioButton::Ptr m_radioRed;
	caUI::RadioButton::Ptr m_radioGreen;
	caUI::RadioButton::Ptr m_radioBlue;
	caUI::Button::Ptr m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif