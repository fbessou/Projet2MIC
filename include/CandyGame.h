#ifndef _CANDY_GAME_H_
#define _CANDY_GAME_H_

namespace Candy
{
  class Game;
};

#include "CandyCommon.h"
#include "CandyGameState.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace Candy
{
  class Game
  {
  private:
    GameState * mCurrentState;
    sf::RenderWindow * mWindow;
    bool hasExited;
    sf::Font mFont;

    sf::Clock mClock;
    unsigned int mFrameCount;
    Real mSPF;
    sf::Text mFPSText;
    void updateDebug();

    sf::Clock clock;
  public:
    Game();
    ~Game();
    void update();
    void start();
    void changeState(GameState * state);
    void quit();
    sf::Font& getFont();

    //			World * getWorld();
  };//class Game
	
}; // namespace Candy

#endif
