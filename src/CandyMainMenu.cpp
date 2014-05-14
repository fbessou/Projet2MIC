#include <iostream>
#include "CandyMainMenu.h"
#include "CandySettings.h"
#include "CandyShip.h"
#include "CandyPlay.h"

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(Game * game, RenderWindow * window):
	GameState(game,window), titleTxt("CANDY SAGA", game->getFont(),100),playTxt("Play the Game",game->getFont(),40), paramTxt("Parameters",game->getFont(),40),quitTxt("Allez voir le dentiste",game->getFont(),40),mWorld(mWindow)
{
	mActiveColor=Color::White;
	mInactiveColor=Color(150,150,150);
	mDisabledColor=Color(90,90,90);

	sf::FloatRect textRect = playTxt.getLocalBounds();
	playTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	playTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));

	textRect = paramTxt.getLocalBounds();
	paramTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	paramTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*4.0/3.0));

	textRect = quitTxt.getLocalBounds();
	quitTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	quitTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*5.0/3.0));

	textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));

	titleTxt.setColor(Color::Red);
	playTxt.setColor(mActiveColor);

	clock.restart();

	keySelection = 0;
	Selected = PLAY;

	newState = nullptr;
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter(){
	mWindow->setTitle("Candy Saga ~Menu~");
}
void MainMenu::leave(){
}

bool MainMenu::update(const Real & timeSinceLastFrame){
	if (clock.getElapsedTime().asSeconds() > 0.12)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			keySelection--;
				clock.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			keySelection++;
				clock.restart();
		}
		keySelection = keySelection>=0 ? keySelection%3 : 2;

		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return))
		{
			switch (Selected)
			{
				case PLAY:
					mGame->changeState(new Play(mGame,mWindow));
					break;
				case SETTINGS:
					mGame->changeState(new Settings(mGame, mWindow,this));
					break;
				case QUIT:
					mGame->quit();
					break;
			}
		}

		switch (keySelection)
		{
			case 0:
				playTxt.setColor(mActiveColor);
				paramTxt.setColor(mInactiveColor);
				quitTxt.setColor(mInactiveColor);
				Selected = PLAY;
				break;
			case 1:
				playTxt.setColor(mInactiveColor);
				paramTxt.setColor(mActiveColor);
				quitTxt.setColor(mInactiveColor);
				Selected = SETTINGS;
				break;
			case 2:
				playTxt.setColor(mInactiveColor);
				paramTxt.setColor(mInactiveColor);
				quitTxt.setColor(mActiveColor);
				Selected = QUIT;
				break;
		}
	}

	mWindow->clear();
	mWindow->draw(titleTxt);
	mWindow->draw(playTxt);
	mWindow->draw(paramTxt);
	mWindow->draw(quitTxt);
	mWorld.step(timeSinceLastFrame);
	mWorld.render();
	return true;
}
