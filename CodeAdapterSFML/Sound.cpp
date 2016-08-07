#include "Sound.h"

#include "CodeAdapter\String.h"




Sound::Sound()
{

}

//###########################################################################

bool Sound::loadFromFile(const String& filename)
{
	bool result = m_buffer.loadFromFile(static_cast<std::string>(filename));
	m_sound.setBuffer(m_buffer);


	return result;
}


void Sound::setVolume(f32 size)
{
	m_sound.setVolume(size);
}

//###########################################################################

void Sound::play(bool loop)
{
	m_sound.setLoop(loop);
	m_sound.play();
}


void Sound::pause()
{
	m_sound.pause();
}


void Sound::stop()
{
	m_sound.stop();
}

