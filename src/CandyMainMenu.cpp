#include "CandyMainMenu.h"
#include "CandySettings.h"

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(Game * game, RenderWindow * window):
  GameState(game,window), playTxt("Play the Game",game->getFont(),40), paramTxt("Parameters",game->getFont(),40),quitTxt("Allez voir le dentiste",game->getFont(),40)
{
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~Menu~");

	sf::FloatRect textRect = playTxt.getLocalBounds();
	playTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	playTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));

	textRect = paramTxt.getLocalBounds();
	paramTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	paramTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*4.0/3.0));

	textRect = quitTxt.getLocalBounds();
	quitTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	quitTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*5.0/3.0));
	
	playTxt.setColor(Color::Yellow);

	clock.restart();

	keySelection = 0;
	Selected = PLAY;

	newState = nullptr;
}

MainMenu::~MainMenu()
{
}

void MainMenu::enter(){}
void MainMenu::leave(){
}

bool MainMenu::update(){
  if (!(clock.getElapsedTime().asSeconds() < 0.12))
    {
      if (Keyboard::isKeyPressed(Keyboard::Up))
	keySelection--;
      if (Keyboard::isKeyPressed(Keyboard::Down))
	keySelection++;
      if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return))
	{
	  switch (Selected)
	    {
	    case PLAY:
	      break;
	    case SETTINGS:
	      mGame->changeState(new Settings(mGame, mWindow));
	      break;
	    case QUIT:
	      mGame->quit();
	      break;

	    }
	}
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
