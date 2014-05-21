#ifndef _CANDY_SETTINGSMENU_H_
#define _CANDY_SETTINGSMENU_H_
#include <string>
#include "CandyGameState.h"

#include <SFML/Graphics.hpp>

namespace Candy
{
  class SettingsMenu: public GameState
  {
    const std::string startButton;
    const std::string exitButton;
    const std::string highscoreButton;
 
  public:
    SettingsMenu(Game * game, sf::RenderWindow * window,GameState* previousState);
    ~SettingsMenu();
    void enter();
    bool update(const Real &);
    void leave();
  private:
    //to remember from where the SettingsMenu State was called and to go back to it
    GameState * mpreviousState;
	std::string mPreviousTitle;

    enum Choice {RETURN};
    int keySelection;
    Choice Selected;
    sf::Clock clock;

    sf::Text returnTxt;
  };
};
#endif
