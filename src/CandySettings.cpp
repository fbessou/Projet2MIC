#include "CandySettings.h"

using namespace Candy;
using namespace sf;


Settings::Settings(Game * game, RenderWindow * window):
  GameState(game,window), playTxt("Play the Game",game->getFont(),30), paramTxt("Parameters",game->getFont(),30),quitTxt("Allez voir le dentiste",game->getFont(),30)
{
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~Lala~");

	playTxt.setPosition(Vector2f(0,mWindow->getSize().y/2.0f));
	paramTxt.setPosition(Vector2f(0,mWindow->getSize().y/5.0*3.0));
	quitTxt.setPosition(Vector2f(0,mWindow->getSize().y/5.0*4.0));
	
	playTxt.setColor(Color::Yellow);

	clock.restart();

	keySelection = 0;
	Selected = PLAY;
}

Settings::~Settings()
{
}

void Settings::enter(){}
void Settings::leave(){}

bool Settings::update(){
  if (!(clock.getElapsedTime().asSeconds() < 0.12))
    {
      if (Keyboard::isKeyPressed(Keyboard::Up))
	keySelection--;
      if (Keyboard::isKeyPressed(Keyboard::Down))
	keySelection++;
    }

  keySelection = keySelection>=0 ? keySelection%3 : 2;

  if (clock.getElapsedTime().asSeconds() > 0.12)
    {
      switch (keySelection)
	{
	case 0:
	  playTxt.setColor(Color::Yellow);
	  paramTxt.setColor(Color::White);
	  quitTxt.setColor(Color::White);
	  Selected = PLAY;
	  clock.restart();
	  break;
	case 1:
	  playTxt.setColor(Color::White);
	  paramTxt.setColor(Color::Yellow);
	  quitTxt.setColor(Color::White);
	  Selected = SETTINGS;
	  clock.restart();
	  break;
	case 2:
	  playTxt.setColor(sf::Color::White);
	  paramTxt.setColor(sf::Color::White);
	  quitTxt.setColor(sf::Color::Yellow);
	  Selected = QUIT;
	  clock.restart();
	  break;
	}
    }

  mWindow->clear();
  mWindow->draw(playTxt);
  mWindow->draw(paramTxt);
  mWindow->draw(quitTxt);
  return true;
}
