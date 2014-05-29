#ifndef _CANDY_SOUND_MANAGER_H_
#define _CANDY_SOUND_MANAGER_H_
#include <SFML/Audio.hpp>
#include <string>
#include "CandySingleton.h"
#include <map>

namespace Candy
{
	class SoundManager : public Singleton<SoundManager>
	{
		private:
			std::map<std::string, sf::SoundBuffer*> mBuffers;
			std::map<std::string, sf::Sound*> mSounds;
		public:
			SoundManager();
			~SoundManager();
			bool addSound(std::string,std::string);
			sf::Sound * getSound(std::string);
	};
};
#endif
