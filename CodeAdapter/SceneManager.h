#ifndef __CA__SCENE_MANAGER_H__
#define __CA__SCENE_MANAGER_H__


#include <memory>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class SceneManager
{
private:
	USING_CA_DRAWING(Window);
	USING_CA_DRAWING(Graphics);


public:
	SceneManager();
	virtual ~SceneManager();


protected:
	std::shared_ptr<Scene> m_scene;


public:
	void replaceScene(Window& owner, std::shared_ptr<Scene> nextScene);
	void update(Window& owner);
	void draw(Graphics& g);
	bool hasScene() const;
};


END_NAMESPACE_CA_UTILITY


#endif