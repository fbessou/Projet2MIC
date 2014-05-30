#include "CandySoundManager.h"
#include <iostream>
#include "CandyMath.h"
using namespace Candy;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
	for(auto sound:mSoundSources)
		delete sound.second;
	for(auto buffer:mBuffers)
		delete buffer.second;

}

bool SoundManager::addSound(std::string name,std::string path)
{
	mBuffers[name]=new sf::SoundBuffer();
	mBuffers[name]->loadFromFile(path);
	mSoundSources[name]=new sf::Sound(*mBuffers[name]);
	return true;
}

bool SoundManager::addMusic(std::string name,std::string path)
{
	sf::Music * m = new sf::Music();
	m->openFromFile(path);
	mSoundSources[name]=m;
	return true;
}

sf::SoundSource * SoundManager::getSound(std::string name)
{
	return mSoundSources[name];
}


void SoundManager::playSound(std::string name, bool interrupt, bool loop)
{
	bool startAgain = false;
	//On ne sait pas si le son demande est une musique (stream)
	sf::Music * m = dynamic_cast<sf::Music*>(mSoundSources[name]);
	if(m!=nullptr)
	{
		m->setLoop(loop);
		startAgain = interrupt || m->getStatus()==sf::SoundSource::Stopped;
		if(startAgain)
			m->play();
	}
	else //ce n'est pas une musique, c'est donc un Sound (buffer)
	{
		sf::Sound * s = static_cast<sf::Sound*>(mSoundSources[name]);
		s->setLoop(loop);
		startAgain = interrupt || m->getStatus()==sf::SoundSource::Stopped;
		if(startAgain)
			s->play();
	}
}

sf::SoundSource::Status SoundManager::getStatus(std::string name)
{
	const sf::Music * m = dynamic_cast<const sf::Music*>(mSoundSources[name]);
	if(m!=nullptr)
	{
		return m->getStatus();
	}
	else //ce n'est pas une musique, c'est donc un Sound (buffer)
	{
		const sf::Sound * s = static_cast<const sf::Sound*>(mSoundSources[name]);
		return s->getStatus();
	}

}


void SoundManager::fadeIn(std::string name,Real time,bool interrupt, bool loop)
{
	sf::SoundSource * s = mSoundSources[name];
	if(getStatus(name) == sf::SoundSource::Stopped || getStatus(name)== sf::SoundSource::Paused)
	s->setVolume(0);
	playSound(name,interrupt,loop);
	mFadedSounds[s]=time;
}

void SoundManager::fadeOut(std::string name,Real time)
{
	sf::SoundSource * s = mSoundSources[name];
	mFadedSounds[s]=-time;
}

void SoundManager::update(Real timeSinceLastFrame)
{
	for(auto it=mFadedSounds.begin();it!=mFadedSounds.end();)
	{
		bool fadeEnd = false;
		if(it->second<0)//fadeOut
		{
			Real remain = -it->second;
			it->second+=timeSinceLastFrame;
			fadeEnd=it->second>0;
			Real volume = 0;
			if(!fadeEnd)
				volume = Math::clamp(it->first->getVolume()*(1-timeSinceLastFrame/remain),0,100);
				it->first->setVolume(volume);
		}
		else//fadeIn
		{
			Real remain = it->second;
			it->second-=timeSinceLastFrame;
			fadeEnd=it->second<0;
			Real volume = 100;
			if(!fadeEnd)
				volume=Math::clamp((100.-it->first->getVolume())*timeSinceLastFrame/remain+it->first->getVolume(),0,100);
			std::cout<<volume<<std::endl;
			it->first->setVolume(volume);

		}
		if(fadeEnd)
			it = mFadedSounds.erase(it);
		else
		   	it++;
	}
}
