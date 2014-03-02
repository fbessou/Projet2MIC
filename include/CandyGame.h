#ifndef _CANDY_GAME_H_
#define _CANDY_GAME_H_

#include "CandyCommon.h"
#include "CandyGameState.h"
//#include "CandyWorld.h"

namespace Candy
{
	class Game
	{
		private:
			GameState * mCurrentState;
//			World * mWorld;
			bool hasExited;
		public:
			Game();
			~Game();
			void update();
			void start();
//			World * getWorld();
	};//class Game
	
}; // namespace Candy

#endif
