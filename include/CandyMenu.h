#ifndef _CANDY_MENU_
#define _CANDY_MENU_

#include "CandyGame.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Candy
{
	class MenuItem
	{
		private:

			std::string mName;
			sf::Vector2f mPosition;
			unsigned int mCharSize;

			bool mSelected;
			//each item stores a function that is triggered when ENTER is pressed
			//callback_function mAction;
			void (*mAction)();
			

		public:
			MenuItem(std::string name, sf::Vector2f position,unsigned int charSize, void (*function)());
			~MenuItem();
			std::string getName();
			sf::Vector2f getPosition();
			unsigned int getCharSize();
			bool getSelected();
			void setSelected(bool s);
			void executeAction();
	};

	class Menu
	{
		private:
			bool mFocused;
			std::vector<MenuItem> mList;
			std::vector<MenuItem>::iterator mActual;

			sf::RenderWindow * mWindow;
			sf::Font mFont;

			sf::Color mActiveColor;
			sf::Color mInactiveColor;
			sf::Color mDisabledColor;

		public:
			Menu(sf::RenderWindow * window,Game *game);
			~Menu();
			//perform function in the MenuItem when ENTER is pressed
			void onSelected();
			void moveUp();
			void moveDown();
			void addItem(MenuItem item);
			void setFocused(bool f);
			void render();
	};
};

#endif
