#include "CandySoundManager.h"

using namespace Candy;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
	for(auto sound:mSounds)
		delete sound.second;
	for(auto buffer:mBuffers)
		delete buffer.second;

}

bool SoundManager::addSound(std::string name,std::string path)
{
	mBuffers[name]=new sf::SoundBuffer();
	mBuffers[name]->loadFromFile(path);
	mSounds[name]=new sf::Sound(*mBuffers[name]);
	return true;
}
sf::Sound * SoundManager::getSound(std::string name)
{
	return mSounds[name];
}
