#ifndef _CANDY_SETTINGS_H_
#define _CANDY_SETTINGS_H_
#include <string>
#include "CandyGameState.h"

#include <SFML/Graphics.hpp>

namespace Candy
{
  class Settings: public GameState
  {
    const std::string startButton;
    const std::string exitButton;
    const std::string highscoreButton;
 
  public:
    Settings(Game * game, sf::RenderWindow * window);
    ~Settings();
    void enter();
    bool update();
    void leave();
  private:
    enum Choice {RETURN};
    int keySelection;
    Choice Selected;
    sf::Clock clock;

    sf::Text returnTxt;
  };
};
#endif
