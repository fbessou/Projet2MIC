#ifndef _CANDY_PLAY_H_
#define _CANDY_PLAY_H_

#include "CandyGameState.h"
#include <SFML/Graphics.hpp>

namespace Candy
{
  class Play : public GameState
  {
  public:
    Play(Game *mgame, sf::RenderWindow *window);
    ~Play();
    void enter();
    bool update();
    void leave();
  };
}

#endif
