#include "Scene.h"




BEGIN_NAMESPACE_CA_UTILITY


template <typename SceneType, typename... ARGS>
void Scene::reserveNextScene(ARGS&&... args)
{
	if (m_nextScene != nullptr)
	{
		if (m_nextScene != this)
		{
			delete m_nextScene;
		}

		m_nextScene = nullptr;
	}

	m_nextScene = new SceneType(std::forward(args)...);
}


END_NAMESPACE_CA_UTILITY

