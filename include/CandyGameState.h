#ifndef _CANDY_GAMESTATE_H_
#define _CANDY_GAMESTATE_H_

namespace Candy
{
	class GameState
	{
		public:
			virtual ~GameState(); // Needed to permit polymorphic destruction
			virtual void enter() = 0;
			virtual bool update() = 0;
			virtual void leave() = 0;
	};
inline GameState::~GameState(){}
};
#endif 
