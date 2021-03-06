#ifndef _CANDY_MENU_H_
#define _CANDY_MENU_H_
#include <string>
#include "CandyGameState.h"
#include "CandyWorld.h"
#include "CandyMenu.h"

#include <SFML/Graphics.hpp>

namespace Candy
{
  class MainMenu: public GameState
  {
    const std::string startButton;
    const std::string exitButton;
    const std::string highscoreButton;
 
  public:
    MainMenu(Game * game, sf::RenderWindow * window);
    ~MainMenu();
    void enter();
    bool update(const Real &);
    void leave();
  private:
    GameState * newState;

    enum Choice {PLAY, SETTINGS, QUIT};
    
	Menu mMenu;
	
	int keySelection;
    Choice Selected;

    sf::Clock clock;

    sf::Text titleTxt;
    sf::Text playTxt;
    sf::Text paramTxt;
    sf::Text quitTxt;

	sf::Color mActiveColor;
	sf::Color mInactiveColor;
	sf::Color mDisabledColor;

	void playGame();


	World mWorld;
  };
};
#endif
