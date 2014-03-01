#ifndef _CANDY_GAMESTATE_H_
#ifndef _CANDY_GAMESTATE_H_
#include <SFML/Graphics.hpp>

namespace Candy
{
	class GameState
	{
		public:
			virtual void enter() = 0;
			virtual void update() = 0;
			virtual void leave() = 0;
	};

	class MainMenu
	{
		std::string startButton;
		std::string exitButton;
		std::string highscoreButton;

		enum Button	{ START, QUIT, SETTINGS };

		public:
			MainMenu();
			~MainMenu();
			void enter();
			void update();
			void leave();


	};
};
#endif 
