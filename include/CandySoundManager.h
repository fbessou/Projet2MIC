#ifndef _CANDY_SOUND_MANAGER_H_
#define _CANDY_SOUND_MANAGER_H_
#include "CandyCommon.h"
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
			std::map<std::string, sf::SoundSource*> mSoundSources;
			std::map<sf::SoundSource*,Real> mFadedSounds;
		public:
			SoundManager();
			~SoundManager();
			bool addSound(std::string,std::string);
			bool addMusic(std::string,std::string);
			void playSound(std::string name, bool interrupt=true, bool loop = false);

			sf::SoundSource::Status  getStatus(std::string name);

			void fadeIn(std::string,Real = 1,bool = false,bool =true);
			void fadeOut(std::string,Real =1);
			sf::SoundSource * getSound(std::string);
			void update(Real);
	};
};
#endif
