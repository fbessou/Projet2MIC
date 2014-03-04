#include "CandyMainMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(Game * game, RenderWindow * window):GameState(game,window),
playTxt("Play the Game",game->getFont(),30)
{
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
