#ifndef _CANDY_GAMESTATE_H_
#define _CANDY_GAMESTATE_H_

#include <SFML/Graphics.hpp>

namespace Candy
{
	class GameState
	{
		public:
			GameState(sf::RenderWindow * window);
			virtual ~GameState(); // Needed to permit polymorphic destruction
			virtual void enter() = 0;
			virtual bool update() = 0;
			virtual void leave() = 0;
			
		protected:
			sf::RenderWindow * mWindow;
	};
inline GameState::~GameState(){}
};
#endif 
