#ifndef __DEMO3_SCENE_H__
#define __DEMO3_SCENE_H__


#include <vector>

#include "CodeAdapter\EasyCA.h"




class Demo3Scene : public caUtil::Scene
{
public:
	Demo3Scene();
	virtual ~Demo3Scene();


protected:
	std::shared_ptr<caDraw::Panel> m_panel;
	std::shared_ptr<caDraw::Font> m_font;
	std::shared_ptr<caUI::TextBox> m_textbox;
	std::shared_ptr<caUI::TextBox> m_textboxRed;
	std::shared_ptr<caUI::TextBox> m_textboxGreen;
	std::shared_ptr<caUI::TextBox> m_textboxBlue;
	std::shared_ptr<caUI::Button> m_buttonNext;


protected:
	caDraw::Color m_effectColor;
	std::vector<caDraw::PointF> m_dotList;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;


private:
	void drawEffect(caDraw::Graphics& g, i32 start, i32 skip);


public:
	void setEffectColorRed(i32 red);
	void setEffectColorGreen(i32 green);
	void setEffectColorBlue(i32 blue);


private:
	void setColor(i32& var, i32 color);
};


#endif