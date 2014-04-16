#include "CandyMainMenu.h"
#include "CandySettings.h"
#include "CandyPlay.h"

using namespace Candy;
using namespace sf;

MainMenu::MainMenu(Game * game, RenderWindow * window):
  GameState(game,window), titleTxt("CANDY SAGA", game->getFont(),100),playTxt("Play the Game",game->getFont(),40), paramTxt("Parameters",game->getFont(),40),quitTxt("Allez voir le dentiste",game->getFont(),40)
{
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~Menu~");
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
	      mGame->changeState(new Play(mGame,mWindow));
	      break;
	    case SETTINGS:
	      mGame->changeState(new Settings(mGame, mWindow,this,"Candy Saga 3 Le Retour des Caries  ~Menu~"));
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
	  playTxt.setColor(mActiveColor);
	  paramTxt.setColor(mInactiveColor);
	  quitTxt.setColor(mInactiveColor);
	  Selected = PLAY;
	  clock.restart();
	  break;
	case 1:
	  playTxt.setColor(mInactiveColor);
	  paramTxt.setColor(mActiveColor);
	  quitTxt.setColor(mInactiveColor);
	  Selected = SETTINGS;
	  clock.restart();
	  break;
	case 2:
	  playTxt.setColor(mInactiveColor);
	  paramTxt.setColor(mInactiveColor);
	  quitTxt.setColor(mActiveColor);
	  Selected = QUIT;
	  clock.restart();
	  break;
	}
    }

  mWindow->clear();
  mWindow->draw(titleTxt);
  mWindow->draw(playTxt);
  mWindow->draw(paramTxt);
  mWindow->draw(quitTxt);
  return true;
}
