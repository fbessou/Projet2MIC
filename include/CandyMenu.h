#ifndef _CANDY_MENU_
#define _CANDY_MENU_

#include "CandyGame.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Candy
{
	class CandyMenuItem
	{
		private:

			typedef void (*callback_function)(void);

			std::string mName;
			sf::Vector2f mPosition;
			bool mSelected;
			//each item stores a function that is triggered when ENTER is pressed
			callback_function mAction;
			

		public:
			CandyMenuItem(std::string name, sf::Vector2f position, callback_function function);
			~CandyMenuItem();
			std::string getName();
			sf::Vector2f getPosition();
			bool getSelected();
			void setSelected(bool s);
			void executeAction();
	};

	class CandyMenu
	{
		private:
			bool mFocused;
			std::vector<CandyMenuItem> mList;
			std::vector<CandyMenuItem>::iterator mActual;

			sf::RenderWindow * mWindow;
			sf::Font mFont;

			sf::Color mActiveColor;
			sf::Color mInactiveColor;
			sf::Color mDisabledColor;

		public:
			CandyMenu(sf::RenderWindow * window,Game *game);
			~CandyMenu();
			//perform function in the MenuItem when ENTER is pressed
			void onSelected();
			void moveUp();
			void moveDown();
			void addItem(CandyMenuItem item);
			void setFocused(bool f);
			void render();
	};
};

#endif
