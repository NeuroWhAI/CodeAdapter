#ifndef __DEMO2_SCENE_H__
#define __DEMO2_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class Demo4Scene : public caUtil::Scene
{
public:
	Demo4Scene();
	virtual ~Demo4Scene();


protected:
	caDraw::Panel::Ptr m_panel;
	caDraw::Font::Ptr m_font;
	caDraw::Font::Ptr m_smallFont;
	caDraw::Panel::Ptr m_panelListBox;
	caUI::ListBox::Ptr m_listBox;
	caUI::TextBox::Ptr m_textBox;
	caUI::Button::Ptr m_buttonAdd;
	caUI::Button::Ptr m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif