#include "CandyGame.h"
#include "CandyMainMenu.h"
using namespace Candy;

Game::Game()
{
	mCurrentState=new MainMenu();
}

Game::~Game()
{
	if(mCurrentState != nullptr)
		delete mCurrentState;
}

void Game::start()
{
	//some init
	while(!hasExited)
	{
		//update inputs
		mCurrentState->update();
	}
}

