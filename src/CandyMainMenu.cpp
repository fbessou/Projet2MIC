#include "CandyMainMenu.h"
#include <iostream>

using namespace Candy;

MainMenu::MainMenu()
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
