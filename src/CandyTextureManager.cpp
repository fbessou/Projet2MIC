#include "CandyTextureManager.h"

using namespace Candy;

TextureManager::TextureManager()
{
	mErrorTexture = new sf::Texture;
	mErrorTexture->loadFromFile("media/error.png");
	
}

TextureManager::~TextureManager()
{
	for(auto textureIt : mTextures)
	{
		delete textureIt.second;
	}
}

bool TextureManager::addTexture(std::string name, std::string path, bool smooth)
{
	sf::Texture * newTexture = new sf::Texture;
	if(newTexture->loadFromFile(path))
	{
		if(smooth)
			newTexture->setSmooth(true);
		mTextures["name"]=newTexture;
		
		return true;
	}
	else
		return false;
}

bool TextureManager::addTexture(std::string name, sf::Image & image,bool smooth)
{
	sf::Texture * newTexture = new sf::Texture;

	if(newTexture->loadFromImage(image))
	{
		if(smooth)
			newTexture->setSmooth(true);
		mTextures["name"]=newTexture;
		
		return true;
	}
	else
		return false;
}

sf::Texture * TextureManager::getTexture(std::string name, bool defaultOnFail)
{
	auto textureIt = mTextures.find(name); 
	if(textureIt == mTextures.end())
		return mErrorTexture;
	return textureIt->second;
}
