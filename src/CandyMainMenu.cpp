#include "CandyMainMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(RenderWindow * window):GameState(window)
{
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~Menu~");	
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter(){}
void MainMenu::leave(){}

int frame=0;

bool MainMenu::update(){
	mWindow->clear(Color(0,50,frame%256,255));
	frame++;
	mWindow->display();
return true;
}
