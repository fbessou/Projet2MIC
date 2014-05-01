#ifndef _CANDY_GAMESTATE_H_
#define _CANDY_GAMESTATE_H_

#include <SFML/Graphics.hpp>

namespace Candy
{
  class GameState;
};

#include "CandyGame.h"

namespace Candy
{
  class GameState
  {
  public:
    GameState(Game * game, sf::RenderWindow * window);
    virtual ~GameState(); // Needed to permit polymorphic destruction
    virtual void enter() = 0;
    virtual bool update(const Real & ) = 0;
    virtual void leave() = 0;
	virtual void onLostFocus();
	virtual void onGainFocus();
			
  protected:
    sf::RenderWindow * mWindow;
    Game * mGame;
  };
};
#endif 
