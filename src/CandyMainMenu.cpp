#include "CandyMainMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(RenderWindow * window):GameState(window)
{
	
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter(){}
void MainMenu::leave(){}
bool MainMenu::update(){
	std::cout<<"Hello"<<std::endl;
return true;
}
