#ifndef _CANDY_GAME_H_
#define _CANDY_GAME_H_

namespace Candy
{
  class Game;
};

#include "CandyCommon.h"
#include "CandyGameState.h"
#include "CandyTextureManager.h"
#include "CandySoundManager.h"
#include "CandySettings.h"
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
    sf::Font mTitleFont;
    sf::Font mFont;
	TextureManager * mTextureManager;
	SoundManager * mSoundManager;
    sf::Clock mClock;
    unsigned int mFrameCount;
    Real mSPF;
    sf::Text mFPSText;
    void updateDebug();

	Settings mSettings;

    sf::Clock clock;
  protected:
	void initResources();
  public:
    Game();
    ~Game();
    void update();
    void start();
    void changeState(GameState * state);
    void quit();
    sf::Font& getFont();
	Settings  & getSettings();
	void setSettings(Settings s);

    //			World * getWorld();
  };//class Game
	
}; // namespace Candy

#endif
