#ifndef __DEMO2_SCENE_H__
#define __DEMO2_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class Demo4Scene : public caUtil::Scene
{
public:
	Demo4Scene();
	virtual ~Demo4Scene();


protected:
	caDraw::PanelPtr m_panel;
	caDraw::FontPtr m_font;
	caDraw::FontPtr m_smallFont;
	caDraw::PanelPtr m_panelListBox;
	caUI::ListBoxPtr m_listBox;
	caUI::TextBoxPtr m_textBox;
	caUI::ButtonPtr m_buttonAdd;
	caUI::ButtonPtr m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif