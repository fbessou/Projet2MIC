#ifndef _Candy_PAUSE_H_
#define _CANDY_PAUSE_H_

#include "CandyGameState.h"
#include "CandyPlay.h"
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

    GameState *mGameSession;
	std::string mPreviousTitle;
    
	sf::RectangleShape  mTransparentLayer;

    sf::Text titleTxt;
    sf::Text returnTxt;
    sf::Text paramTxt;
    sf::Text exitGameTxt;
    sf::Text quitAppTxt;
    sf::Color mActiveColor;
    sf::Color mInactiveColor;
    sf::Color mDisabledColor;

    sf::Clock clock;
  };
}

#endif
