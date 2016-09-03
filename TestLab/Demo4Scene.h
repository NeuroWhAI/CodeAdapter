#ifndef __DEMO2_SCENE_H__
#define __DEMO2_SCENE_H__


#include "CodeAdapter\EasyCA.h"




class Demo4Scene : public caUtil::Scene
{
public:
	Demo4Scene();
	virtual ~Demo4Scene();


protected:
	caUtil::ResourcePool m_pool;


protected:
	std::shared_ptr<caDraw::Panel> m_panel;
	std::shared_ptr<caDraw::Font> m_font;
	std::shared_ptr<caDraw::Font> m_smallFont;
	std::shared_ptr<caDraw::Panel> m_panelListBox;
	std::shared_ptr<caUI::ListBox> m_listBox;
	std::shared_ptr<caUI::TextBox> m_textBox;
	std::shared_ptr<caUI::Button> m_buttonAdd;
	std::shared_ptr<caUI::Button> m_buttonNext;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;
};


#endif