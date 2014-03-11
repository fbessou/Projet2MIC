#include "CandyGame.h"
#include "CandyMainMenu.h"
#include <cassert>
using namespace Candy;
Game::Game():mCurrentState(nullptr),hasExited(false)
{
	assert(mFont.loadFromFile("./font/Transformers_Movie.ttf") && "pad'font");
}

Game::~Game()
{
	if(mCurrentState != nullptr)
		delete mCurrentState;
	delete mWindow;
}

void Game::start()
{
	sf::Uint32 windowStyle = (sf::Style::Titlebar | sf::Style::Close) ; //TODO enable fullscreen
	mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "CandySaga",windowStyle);
	sf::VideoMode screen = sf::VideoMode::getDesktopMode();
	//center the window
	mWindow->setPosition(sf::Vector2i(screen.width/2-mWindow->getSize().x/2, screen.height/2-mWindow->getSize().y/2));
	//fix maximum framerate
	mWindow->setFramerateLimit(60);

	mCurrentState=new MainMenu(this, mWindow);
	//some init

	while(!hasExited)
	{

		sf::Event event;
		//update inputs
		mCurrentState->update();
		while (mWindow->isOpen() && mWindow->pollEvent(event)){
			if(event.type == sf::Event::Closed)
			{
				hasExited=true;
			}
		}
	}
	//mWindow->close();
}

sf::Font& Game::getFont()
{
	return mFont;
}

void Game::quit()
{
	hasExited = true;
}

void Game::changeState(GameState * state)
{
	mCurrentState->leave();
	mCurrentState=state;
	mCurrentState->enter();
}
