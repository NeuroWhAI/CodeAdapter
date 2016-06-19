#ifndef __CA__SCENE_H__
#define __CA__SCENE_H__


#include <memory>
#include <vector>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class Scene
{
	friend SceneManager;


private:
	USING_CA_DRAWING(Window);
	USING_CA_DRAWING(Panel);
	USING_CA_DRAWING(Graphics);


public:
	Scene();
	virtual ~Scene();


private:
	Scene* m_nextScene;


protected:
	std::vector<std::shared_ptr<Panel>> m_panelList;


public:
	void initialize(Window& owner);
	void release();
	void update(Window& win);
	void draw(Graphics& g);


protected:
	virtual void onInitialize(Window& owner) = 0;
	virtual void onRelease() = 0;
	virtual void onUpdate(Window& owner) = 0;
	virtual void onDraw(Graphics& g) = 0;


protected:
	template <typename SceneType, typename... ARGS>
	void reserveNextScene(ARGS&&... args);
	void reserveNextScene(std::nullptr_t);


private:
	Scene* getNextScene();
	void clearNextScene();


public:
	bool addPanel(std::shared_ptr<Panel> panel);
	bool removePanel(std::shared_ptr<const Panel> panel);
};


END_NAMESPACE_CA_UTILITY


#include "Scene.inl"


#endif