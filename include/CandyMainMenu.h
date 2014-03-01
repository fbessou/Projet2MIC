#ifndef _CANDY_MENU_H_
#define _CANDY_MENU_H_
#include "CandyGameState.h"

namespace Candy
{
	class MainMenu: public GameState
	{
		const std::string startButton;
		const std::string exitButton;
		const std::string highscoreButton;

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
