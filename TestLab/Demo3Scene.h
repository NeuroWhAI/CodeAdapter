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
	caDraw::PanelPtr m_panel;
	caDraw::FontPtr m_font;
	caDraw::FontPtr m_smallFont;
	caUI::TextBoxPtr m_textbox;
	caUI::TextBoxPtr m_textboxRed;
	caUI::TextBoxPtr m_textboxGreen;
	caUI::TextBoxPtr m_textboxBlue;
	caUI::TextBoxPtr m_textboxNote;
	caDraw::PanelPtr m_notePanel;
	caUI::ButtonPtr m_buttonNext;


protected:
	caDraw::Color m_effectColor;
	f32 m_speed;
	std::vector<caDraw::PointF> m_dotList;


public:
	virtual void onInitialize(caDraw::Window& owner) override;
	virtual void onRelease() override;
	virtual void onUpdate(caDraw::Window& owner) override;
	virtual void onDrawBack(caDraw::Graphics& g) override;
	virtual void onDrawFront(caDraw::Graphics& g) override;


private:
	void drawEffect(caDraw::Graphics& g, i32 start, i32 skip,
		const caDraw::Color& color, const caDraw::PointF& offset);


public:
	void setEffectColorRed(i32 red);
	void setEffectColorGreen(i32 green);
	void setEffectColorBlue(i32 blue);


private:
	void setColor(i32& var, i32 color);
};


#endif