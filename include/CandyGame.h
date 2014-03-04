#ifndef _CANDY_GAME_H_
#define _CANDY_GAME_H_

namespace Candy
{
	class Game;
};

#include "CandyCommon.h"
#include "CandyGameState.h"
#include <SFML/Graphics.hpp>


namespace Candy
{
	class Game
	{
		private:
			GameState * mCurrentState;
//			World * mWorld;
			sf::RenderWindow * mWindow;
			bool hasExited;
			sf::Font mFont;
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
