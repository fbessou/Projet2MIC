#ifndef _CANDY_PLAY_H_
#define _CANDY_PLAY_H_

#include "CandyGameState.h"
#include "CandyWorld.h"
#include <SFML/Graphics.hpp>

namespace Candy
{
  class Play : public GameState
  {
	  private:
	  sf::Sprite  mBackground;
	  protected:
		World mWorld;
	  public:
    Play(Game *mgame, sf::RenderWindow *window);
    ~Play();
    void enter() override;
    bool update(const Real &) override;
    void leave() override;

	void onLostFocus() override;
	
  };
}

#endif
