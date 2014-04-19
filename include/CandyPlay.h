#ifndef _CANDY_PLAY_H_
#define _CANDY_PLAY_H_

#include "CandyGameState.h"
#include "CandyWorld.h"
#include <SFML/Graphics.hpp>

namespace Candy
{
  class Play : public GameState
  {
	  protected:
		World mWorld;
	  public:
    Play(Game *mgame, sf::RenderWindow *window);
    ~Play();
    void enter();
    bool update(const Real &);
    void leave();
  };
}

#endif
