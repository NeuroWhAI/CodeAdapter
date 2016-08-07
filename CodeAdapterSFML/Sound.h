#ifndef __CA_SFML__SOUND_H__
#define __CA_SFML__SOUND_H__


#include "CodeAdapter\Sound.h"

#include "SFML\Audio.hpp"




class Sound : public CodeAdapter::Audio::Sound
{
private:
	USING_CA(f32);

	USING_CA_UTILITY(String);


public:
	Sound();
	virtual ~Sound() = default;


protected:
	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;


public:
	virtual bool loadFromFile(const String& filename) override;
	virtual void setVolume(f32 size) override;


public:
	virtual void play(bool loop = false) override;
	virtual void pause() override;
	virtual void stop() override;
};


#endif