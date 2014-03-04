#ifndef _CANDY_MENU_H_
#define _CANDY_MENU_H_
#include <string>
#include "CandyGameState.h"

#include <SFML/Graphics.hpp>

namespace Candy
{
	class MainMenu: public GameState
	{
		const std::string startButton;
		const std::string exitButton;
		const std::string highscoreButton;

		enum Button	{ START, QUIT, SETTINGS };

		public:
		MainMenu(Game * game, sf::RenderWindow * window);
		~MainMenu();
		void enter();
		bool update();
		void leave();
		private:
		sf::Text playTxt;
		sf::Text paramTxt;
		sf::Text quitTxt;
	};
};
#endif
