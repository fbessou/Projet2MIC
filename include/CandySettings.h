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
    SettingsMenu(Game * game, sf::RenderWindow * window);
    ~SettingsMenu();
    void enter();
    bool update();
    void leave();
  private:
    enum Choice {PLAY, SETTINGS, QUIT};
    int keySelection;
    Choice Selected;
    sf::Clock clock;

    sf::Text playTxt;
    sf::Text paramTxt;
    sf::Text quitTxt;
  };
};
#endif
