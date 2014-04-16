#include "CandySettings.h"

using namespace Candy;
using namespace sf;


Settings::Settings(Game * game, RenderWindow * window, GameState * previousState,string previousTitle):
  GameState(game,window), returnTxt("Return to main menu",game->getFont(),40)
{
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~The Empty Menu~");
	mPreviousTitle = previousTitle;

	sf::FloatRect textRect = returnTxt.getLocalBounds();
	returnTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	returnTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));
	
	returnTxt.setColor(Color::White);

	mpreviousState = previousState;
	mPreviousTitle = previousTitle;

	clock.restart();

	keySelection = 0;
	Selected = RETURN;
}

Settings::~Settings()
{
}

void Settings::enter(){}
void Settings::leave(){}

bool Settings::update(){
 
  mWindow->clear();
  mWindow->draw(returnTxt);

  if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return))
    {
      mWindow->setTitle(mPreviousTitle);
      mGame->changeState(mpreviousState);
      delete this;
    }

  return true;
}
