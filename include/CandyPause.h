#ifndef _Candy_PAUSE_H_
#define _CANDY_PAUSE_H_

#include "CandyGameState.h"
#include "CandyPlay.h"
#include "CandyMenu.h"
#include <SFML/Graphics.hpp>
#include <string>

namespace Candy
{
  class Pause: public GameState
  {
  public:
    Pause(Game *game, sf::RenderWindow *window, Play *gameSession);
    ~Pause();
    void enter();
    bool update(const Real & );
    void leave();

  private:
    enum Choice {PLAY, SETTINGS, MAINMENU, QUIT};
    int keySelection;
    Choice Selected;

    Play *mGameSession;
	std::string mPreviousTitle;
    
	sf::RectangleShape  mTransparentLayer;

    sf::Text titleTxt;

    sf::Clock clock;

	Menu mMenu;
  };
}

#endif
