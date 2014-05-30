#include "CandyGame.h"
#include "CandyMainMenu.h"
#include <cassert>
#include <sstream>
#include <iostream>

using namespace Candy;

Game::Game():mCurrentState(nullptr),hasExited(false),mFrameCount(0),mFPSText(),mSettings()
{
	assert(mFont.loadFromFile("./font/Transformers_Movie.ttf") && "pad'font");
	
	//make a sf::text showing the current frame per seconds
	mFPSText.setFont(mFont);
	mFPSText.setColor(sf::Color::White);
	mFPSText.setPosition(10,0.5);
	mFPSText.setCharacterSize(15);
	//We hope the framerate will be 60fps
	//as the computed fps is smoothed with the previous one at each frame
	//we set the first value of fps to 60fps
	mSPF=1.0/60.0;
	initResources();
}

Game::~Game()
{
	//destroy the state the game is in before
	//quitting
	if(mCurrentState != nullptr)
		delete mCurrentState;

	delete mWindow;
	delete mTextureManager;
	delete mSoundManager;
}

void Game::start()
{
	//Create a window to display the game
	sf::Uint32 windowStyle = (sf::Style::Titlebar | sf::Style::Close) ; //TODO enable fullscreen
	mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "CandySaga",windowStyle);

	//center the window
	sf::VideoMode screen = sf::VideoMode::getDesktopMode();
	mWindow->setPosition(sf::Vector2i(screen.width/2-mWindow->getSize().x/2, screen.height/2-mWindow->getSize().y/2));

	//Limit the framerate
	mWindow->setFramerateLimit(60);
	
	//Enter the MainMenu state
	mCurrentState=new MainMenu(this, mWindow);
	mCurrentState->enter();

	while(!hasExited)
	{
		update();
		updateDebug();
		mWindow->display();
	}
	//mWindow->close();
}

sf::Font& Game::getFont()
{
	return mFont;
}

const Settings & Game::getSettings() const
{
	return mSettings;
}

void Game::update()
{
		sf::Event event;
		
		mSoundManager->update(mSPF);
		mCurrentState->update(mSPF);

		while (mWindow->isOpen() && mWindow->pollEvent(event) && !hasExited){
			switch(event.type)
			{
				case sf::Event::Closed:
					hasExited=true; //end the app
					break;
				case sf::Event::LostFocus:
					mCurrentState->onLostFocus(); //mainly used to enter pause in game
					break;
				default:
					break;
			}
		}

}


void Game::updateDebug()
{
	mSPF = mSPF*0.5 + mClock.getElapsedTime().asSeconds()*0.5;

	if(mFrameCount++%30 == 0)
	{
		mFPSText.setString( std::string("FPS : ")+std::to_string(1./mSPF));
	}
	mWindow->draw(mFPSText);
	mClock.restart();
}

void Game::initResources()
{
	mTextureManager = new TextureManager();
	mSoundManager = new SoundManager();
	sf::Texture * tex;
	tex = mTextureManager->addTexture("NightSky","media/sky.png");
	tex->setRepeated(true);

	mTextureManager->addTexture("BlueShip","media/ship.png");
	mTextureManager->addTexture("Bullet","media/projectile.png");
	mTextureManager->addTexture("Rocket","media/rocket.png");
	mTextureManager->addTexture("BonusM","media/bonusM.png");
	mTextureManager->addTexture("Flare","media/flare.png");
	mTextureManager->addTexture("AsteroidDefault","media/asteroid.png");
	mTextureManager->addTexture("AsteroidLife","media/asteroidLife.png");
	mTextureManager->addTexture("AsteroidRocket","media/asteroidRocket.png");
	mSoundManager->addSound("0","media/do.ogg");
	mSoundManager->addSound("1","media/re.ogg");
	mSoundManager->addSound("2","media/fa.ogg");
	mSoundManager->addSound("3","media/sol.ogg");
	mSoundManager->addSound("4","media/la.ogg");
	mSoundManager->addSound("5","media/do2.ogg");
	mSoundManager->addSound("6","media/re2.ogg");
	mSoundManager->addSound("LifeUp","media/lifeup.ogg");
	mSoundManager->addSound("Damage1","media/action1.ogg");
	mSoundManager->addSound("Damage2","media/action2.ogg");
	mSoundManager->addSound("Damage3","media/action3.ogg");
	mSoundManager->addMusic("MenuMusic","media/menu.ogg");
}

void Game::quit()
{
	hasExited = true;
}

void Game::changeState(GameState * state)
{
	mCurrentState->leave();
	clock.restart();
	// to avoid instant transition, because prgm will behave as if user is holding key
	while (clock.getElapsedTime().asSeconds()<0.1){}
	mCurrentState=state;
	mCurrentState->enter();
}
