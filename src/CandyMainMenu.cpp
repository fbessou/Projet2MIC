#include <iostream>
#include "CandyMainMenu.h"
#include "CandySettingsMenu.h"
#include "CandyShip.h"
#include "CandyPlay.h"

using namespace Candy;
using namespace sf;
using namespace std;

MainMenu::MainMenu(Game * game, RenderWindow * window):
	GameState(game,window),mMenu(window,game), titleTxt("CANDY SAGA", game->getFont(),100),
	playTxt("Nouveau Match",game->getFont(),40), 
	paramTxt("Configuration",game->getFont(),40),
	quitTxt("Quitter",game->getFont(),40),
	mWorld(mWindow)
{
	mActiveColor=Color::White;
	mInactiveColor=Color(150,150,150);
	mDisabledColor=Color(90,90,90);

	mMenu.addItem(MenuItem("Nouveau Match",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f),40,NULL));
	mMenu.addItem(MenuItem("Configuration",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*4.0/3.0),40,NULL));
	mMenu.addItem(MenuItem("Quitter",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*5.0/3.0),40,NULL));
	mMenu.setFocused(true);

	sf::FloatRect textRect = playTxt.getLocalBounds();
	textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));

	titleTxt.setColor(Color::Red);

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
	SoundManager::getInstance().fadeIn("MenuMusic",10);
}
void MainMenu::leave(){
}

bool MainMenu::update(const Real & timeSinceLastFrame){
	if (clock.getElapsedTime().asSeconds() > 0.12)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			mMenu.moveUp();
			keySelection--;
			clock.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			mMenu.moveDown();
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
					SoundManager::getInstance().fadeOut("MenuMusic");
					break;
				case SETTINGS:
					mGame->changeState(new SettingsMenu(mGame, mWindow,this));
					break;
				case QUIT:
					mGame->quit();
					break;
			}
		}

		switch (keySelection)
		{
			case 0:
				Selected = PLAY;
				break;
			case 1:
				Selected = SETTINGS;
				break;
			case 2:
				Selected = QUIT;
				break;
		}
	}

	mWindow->clear();
	mWindow->draw(titleTxt);
	mMenu.render();
	mWorld.step(timeSinceLastFrame);
	mWorld.render();
	return true;
}
