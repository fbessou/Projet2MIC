#ifndef _CANDY_PLAY_H_
#define _CANDY_PLAY_H_

#include <SFML/Graphics.hpp>
#include "CandyGameState.h"
#include "CandyWorld.h"
#include "CandyTeam.h"
#include "CandyShip.h"
namespace Candy
{
  class Play : public GameState
  {
	  private:
	  sf::Sprite  mBackground;
	  Team * mTeam1;
	  Team * mTeam2;
	  Ship * mShip1;
	  Ship * mShip2;
	  protected:
	  World mWorld;
	  Real mClock;
	  
	  void showOverlays() const;
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
