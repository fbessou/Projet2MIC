#include "CandyMainMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;
double a = 0.0;
MainMenu::MainMenu(Game * game, RenderWindow * window):
  GameState(game,window), playTxt("Play the Game",game->getFont(),mWindow->getSize().y*0.1), paramTxt("Parameters",game->getFont(),mWindow->getSize().y*0.1),quitTxt("Allez voir le dentiste",game->getFont(),mWindow->getSize().y*0.1)
{
  playTxt.setPosition(0.5,0.5);
  sf::FloatRect textRect = playTxt.getLocalBounds();
  playTxt.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
  //playTxt.setPosition(sf::Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));
  playTxt.setPosition(sf::Vector2f(0,mWindow->getSize().y/2.0f));
  mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~Menu~");
  paramTxt.setPosition(sf::Vector2f(0,mWindow->getSize().y/5.0*3.0));
  quitTxt.setPosition(sf::Vector2f(0,mWindow->getSize().y/5.0*4.0));

  Selection = QUIT;
  keyValue = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter(){}
void MainMenu::leave(){}

bool MainMenu::update(){
  if(a<1)
    {
      playTxt.setPosition(sf::Vector2f(a*mWindow->getSize().x/2,mWindow->getSize().y/2.0f));
      a+=0.01;
    }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      keyValue++;
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      keyValue--;
    }

  keyValue = keyValue>=0 ? keyValue%3 : (keyValue+3);

  switch (keyValue)
    {
    case 0:
      Selection = PLAY;
      break;
    case 1:
      Selection = SETTINGS;
      break;
    case 2:
      Selection = QUIT;
      break;
    }

  //Change the color of the selected option before updating
  switch (Selection)
    {
    case PLAY:
      playTxt.setColor(sf::Color::Yellow);
      paramTxt.setColor(sf::Color::White);
      quitTxt.setColor(sf::Color::White);
      break;
    case SETTINGS:
      playTxt.setColor(sf::Color::White);
      paramTxt.setColor(sf::Color::Yellow);
      quitTxt.setColor(sf::Color::White);
      break;
    case QUIT:
      playTxt.setColor(sf::Color::White);
      paramTxt.setColor(sf::Color::White);
      quitTxt.setColor(sf::Color::Yellow);
      break;
    }

  mWindow->clear();
  mWindow->draw(playTxt);
  mWindow->draw(paramTxt);
  mWindow->draw(quitTxt);
  mWindow->display();
  return true;
}
