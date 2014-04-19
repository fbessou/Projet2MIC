#include "CandySettings.h"

using namespace Candy;
using namespace sf;


Settings::Settings(Game * game, RenderWindow * window, GameState * previousState):
  GameState(game,window), returnTxt("Return to main menu",game->getFont(),40)
{

	sf::FloatRect textRect = returnTxt.getLocalBounds();
	returnTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	returnTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));
	
	returnTxt.setColor(Color::White);

	mpreviousState = previousState;

	clock.restart();

	keySelection = 0;
	Selected = RETURN;
}

Settings::~Settings()
{
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries  ~The Empty Menu~");
}

void Settings::enter(){

}
void Settings::leave(){}

bool Settings::update(const Real & timeSinceLastFrame){
 
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
