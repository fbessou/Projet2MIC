#include "CandyGame.h"
#include "CandyMainMenu.h"
#include <cassert>
using namespace Candy;

Game::Game():hasExited(false)
{
	assert(mFont.loadFromFile("./font/Transformers_Movie.ttf") && "pad'font");
}

Game::~Game()
{
	if(mCurrentState != nullptr)
		delete mCurrentState;
}

void Game::start()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "CandySaga");
	mWindow->setFramerateLimit(60);

	mCurrentState=new MainMenu(this, mWindow);
	//some init

	while(!hasExited)
	{

		sf::Event event;
		while (mWindow->isOpen() && mWindow->pollEvent(event)){
			if(event.type == sf::Event::Closed)
			{
				hasExited=true;
			}
		}
		//update inputs
		mCurrentState->update();
	}
	mWindow->close();
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
