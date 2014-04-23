#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <SFML/Graphics.hpp>
#include <string>
#include "CandySingleton.h"
namespace Candy
{
	class TextureManager:public Singleton<TextureManager>{
		private:
			std::map<std::string,sf::Texture*> mTextures;
			sf::Texture * mErrorTexture;
		public:
			TextureManager();
			~TextureManager();
			bool addTexture(std::string name, std::string path,bool =true);
			bool addTexture(std::string name, sf::Image &, bool = true );
			sf::Texture * getTexture(std::string name, bool defaultOnFail);


	};
};
#endif
