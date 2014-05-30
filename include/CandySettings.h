#ifndef _CANDY_SETTINGS_
#define _CANDY_SETTINGS_
#include <SFML/Window.hpp>
// ~ where all the settings are hard-coded ~

namespace Candy
{
	struct KeyBinding
	{
		sf::Keyboard::Key primary;
		sf::Keyboard::Key secondary;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key forward;
	};

	class Settings
	{
		public:
			Settings();
			KeyBinding mBinding1;
			KeyBinding mBinding2;
			// float mVolume;
			// bool mMute;
			void saveSettings(KeyBinding k1, KeyBinding k2);
			void loadDefault();
			std::string keyToString(sf::Keyboard::Key k);
	};
};
#endif
