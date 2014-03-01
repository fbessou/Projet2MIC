#ifndef _CANDY_GAMESTATE_H_
#ifndef _CANDY_GAMESTATE_H_

namespace Candy
{
	class GameState
	{
		public:
			virtual void enter() = 0;
			virtual void update() = 0;
			virtual void leave() = 0;
	};

};
#endif 
