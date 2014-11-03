#ifndef _CANDY_SETTINGSMENU_H_
#define _CANDY_SETTINGSMENU_H_
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
    //to remember from where the SettingsMenu State was called and to go back to it
    GameState * mpreviousState;
	std::string mPreviousTitle;
	Settings mCurrentSettings;

    enum Choice {KEYBOARD=0, VOLUME, DISPLAY, RETURN};
	enum Menu {MENU1=0, MENU2};
	enum keyMenu {PRIMARY1=0,SECONDARY1,LEFT1,RIGHT1,FORWARD1,PRIMARY2,SECONDARY2,LEFT2,RIGHT2,FORWARD2,SAVE,RESTORE};
    Choice Selected;
	Menu SelectedMenu;
	keyMenu SelectedKey;
    sf::Clock clock;

	sf::Color mActiveColor;
	sf::Color mInactiveColor;
	
	sf::Text titleTxt;

	sf::Text keyboardTxt;
	sf::Text player1Txt;
	sf::Text primary1Txt;
	sf::Text p1ValueTxt;
	sf::Text secondary1Txt;
	sf::Text s1ValueTxt;
	sf::Text left1Txt;
	sf::Text l1ValueTxt;
	sf::Text right1Txt;
	sf::Text r1ValueTxt;
	sf::Text forward1Txt;
	sf::Text f1ValueTxt;
	sf::Text player2Txt;
	sf::Text primary2Txt;
	sf::Text p2ValueTxt;
	sf::Text secondary2Txt;
	sf::Text s2ValueTxt;
	sf::Text left2Txt;
	sf::Text l2ValueTxt;
	sf::Text right2Txt;
	sf::Text r2ValueTxt;
	sf::Text forward2Txt;
	sf::Text f2ValueTxt;
	sf::Text saveTxt;
	sf::Text restoreTxt;

	sf::Text volumeTxt;
	sf::Text volTxt;
//	sf::Text setVolumeTxt;
//	sf::Text setMuteTxt;
//	enum Volume {SETVOLUME, SETMUTE};
//	Volume SelectedVolume;

	sf::Text displayTxt;
	sf::Text dispTxt;

    sf::Text returnTxt;

    sf::Text keySelectTxt;
	sf::RectangleShape menu1Rect;
	sf::RectangleShape menu2Rect;

	Menu mMenu;
  };
};
#endif
