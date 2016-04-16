#ifndef __CA__FACTORY_H__
#define __CA__FACTORY_H__


#include <memory>

#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_DRAWING


class Window;
class TextArtist;
class RectangleArtist;


END_NAMESPACE_CA_DRAWING


BEGIN_NAMESPACE_CA


class Factory
{
public:
	Factory();
	virtual ~Factory();


private:
	static Factory* s_pInstance;

	class CleanUp
	{
	public:
		virtual ~CleanUp()
		{
			if (s_pInstance != nullptr)
			{
				delete s_pInstance;
				s_pInstance = nullptr;
			}
		}
	};

	static CleanUp s_cleaner;


public:
	template <typename T>
	static void initializeInstance();
	static Factory* getInstance();


public:
	virtual std::shared_ptr<Drawing::Window> createWindow() = 0;
	virtual std::shared_ptr<Drawing::TextArtist> createTextArtist() = 0;
	virtual std::shared_ptr<Drawing::RectangleArtist> createRectangleArtist() = 0;
};


END_NAMESPACE_CA


#include "Factory.inl"


#endif