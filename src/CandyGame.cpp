#include "CandyGame.h"
#include "CandyMainMenu.h"
#include <cassert>
#include <sstream>
#include <iostream>

using namespace Candy;

Game::Game():mCurrentState(nullptr),hasExited(false),mFPSText()
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
}

Game::~Game()
{
	//destroy the state the game is in before
	//quitting
	if(mCurrentState != nullptr)
		delete mCurrentState;

	delete mWindow;
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

void Game::update()
{
		sf::Event event;
		
		mCurrentState->update();

		while (mWindow->isOpen() && mWindow->pollEvent(event)){
			if(event.type == sf::Event::Closed)
			{
				hasExited=true;
			}
		}
		

}
void Game::updateDebug()
{
	mSPF = mSPF*0.5 + mClock.getElapsedTime().asSeconds()*0.5;

	if(mFrameCount++%30 == 0)
	{
		mFPSText.setString( string("FPS : ")+std::to_string(1./mSPF));
	}
	mWindow->draw(mFPSText);
	mClock.restart();
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

