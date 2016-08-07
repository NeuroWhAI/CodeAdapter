#ifndef __CA__SOUND_H__
#define __CA__SOUND_H__


#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_AUDIO


class Sound
{
private:
	USING_CA_UTILITY(String);


public:
	Sound();
	virtual ~Sound() = default;


public:
	virtual bool loadFromFile(const String& filename) = 0;
	virtual void setVolume(f32 size) = 0;


public:
	virtual void play(bool loop = false) = 0;
	virtual void pause() = 0;
	virtual void stop() = 0;
};


END_NAMESPACE_CA_AUDIO


#endif	