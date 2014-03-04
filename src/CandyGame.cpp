#include "CandyGame.h"
#include "CandyMainMenu.h"
using namespace Candy;

Game::Game():hasExited(false)
{
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

	mCurrentState=new MainMenu(mWindow);
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

