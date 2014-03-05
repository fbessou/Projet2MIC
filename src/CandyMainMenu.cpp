#include "CandyMainMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(Game * game, RenderWindow * window):GameState(game,window),
playTxt("Play the Game",game->getFont(),30)
{
	playTxt.setPosition(0.5,0.5);
	sf::FloatRect textRect = playTxt.getLocalBounds();
	playTxt.setOrigin(textRect.left + textRect.width/2.0f,
			textRect.top  + textRect.height/2.0f);
	playTxt.setPosition(sf::Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~Menu~");
	//	playTxt.setColor(Color::White);
	/*
	   options.setString("Parameters");
	   options.setColor(Color::Red);

	   quit.setString("Aller voir le dentiste");
	   quit.setColor(Color::Yellow); */
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter(){}
void MainMenu::leave(){}

bool MainMenu::update(){
	mWindow->clear();
	mWindow->draw(playTxt);
	mWindow->display();
	return true;
}
