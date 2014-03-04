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
	mCurrentState=new MainMenu(mWindow);
	//some init
	while(!hasExited)
	{
		//update inputs
		mCurrentState->update();
	}
}

