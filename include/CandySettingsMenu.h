#ifndef _CANDY_SETTINGSsubMenu_H_
#define _CANDY_SETTINGSsubMenu_H_
#include <string>
#include "CandyGameState.h"
#include "CandySettings.h"
#include "CandyMenu.h"
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
    //to remember from where the SettingssubMenu State was called and to go back to it
    GameState * mpreviousState;
	std::string mPreviousTitle;
	Settings mCurrentSettings;

    enum Choice {KEYBOARD=0, VOLUME, DISPLAY, RETURN};
	enum subMenu {MENU1=0, MENU2};
	enum keyMenu {PRIMARY1=0,SECONDARY1,LEFT1,RIGHT1,FORWARD1,PRIMARY2,SECONDARY2,LEFT2,RIGHT2,FORWARD2,SAVE,RESTORE};
    Choice Selected;
	subMenu SelectedMenu;
	keyMenu SelectedKey;
    sf::Clock clock;

	sf::Color mActiveColor;
	sf::Color mInactiveColor;
	
	sf::Text titleTxt;
	sf::Text player1Txt;
	sf::Text player2Txt;
	sf::Text volTxt;
//	sf::Text setVolumeTxt;
//	sf::Text setMuteTxt;
//	enum Volume {SETVOLUME, SETMUTE};
//	Volume SelectedVolume;

	sf::Text dispTxt;

    sf::Text keySelectTxt;
	sf::RectangleShape menu1Rect;
	sf::RectangleShape menu2Rect;

	Menu mMainMenu;
	Menu mKeyMenu;
	Menu mKeyValueMenu;
  };
};
#endif
