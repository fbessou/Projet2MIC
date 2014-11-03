#include "CandySettingsMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;
using namespace std;

SettingsMenu::SettingsMenu(Game * game, RenderWindow * window, GameState * previousState):
  GameState(game,window),
	mCurrentSettings(game->getSettings()),
	titleTxt("Configuration",game->getFont(),100),
	player1Txt("Joueur 1 : ",game->getFont(),30),
	player2Txt("Joueur 2 : ",game->getFont(),30),
	volTxt("Not implemented yet",game->getFont(),40),
	dispTxt("Nor this one",game->getFont(),40),
	keySelectTxt("[...]",game->getFont(),20),
	menu1Rect(sf::Vector2f(mWindow->getSize().x/3.,mWindow->getSize().y*2./3)),
	menu2Rect(sf::Vector2f(mWindow->getSize().x*2./3,mWindow->getSize().y*2./3.)),
	mMainMenu(window,game),mKeyMenu(window,game),mKeyValueMenu(window,game)
{
	sf::FloatRect textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));

	// menu for player 1 's keyboard
	textRect = player1Txt.getLocalBounds();
	player1Txt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	player1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*2.0/3.0));
	textRect = player2Txt.getLocalBounds();
	player2Txt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	player2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*15.0/12.0));
	
	//for when I implement the Origin in MenuItem
	//r2ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	
	textRect = volTxt.getLocalBounds();
	volTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	volTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*4.0/3.0,mWindow->getSize().y/2.0f));

	textRect = dispTxt.getLocalBounds();
	dispTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	dispTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*4.0/3.0,mWindow->getSize().y/2.0f));

	//Added for a better visibility
	textRect = keySelectTxt.getLocalBounds();
	keySelectTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	keySelectTxt.setPosition(Vector2f(mWindow->getSize().x/2.,mWindow->getSize().y-15));

	menu1Rect.setPosition(0,mWindow->getSize().y/4.+20);
	menu2Rect.setPosition(menu1Rect.getSize().x,mWindow->getSize().y/4.+20);
	menu1Rect.setFillColor(Color(10,10,10,255));
	menu2Rect.setFillColor(Color(5,5,5,255));

	mActiveColor = Color::White;
	mInactiveColor = Color(150,150,150);

	titleTxt.setColor(Color::Red);

	player1Txt.setColor(Color::Green);
	player2Txt.setColor(Color::Green);

	volTxt.setColor(Color::Green);
	//	setVolumeTxt.setColor(mActiveColor);
	//	setMuteTxt.setColor(mInactiveColor);
	//	SelectedVolume = VOLUME;

	dispTxt.setColor(Color::Green);

	keySelectTxt.setColor(Color::White);

	mpreviousState = previousState;

	clock.restart();

	Selected = KEYBOARD;
	SelectedMenu = MENU1;
	SelectedKey = PRIMARY1;

	mMainMenu.addItem(MenuItem("Clavier",Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f*2.0/3.0),40,NULL));
	mMainMenu.addItem(MenuItem("Volume",Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f),40,NULL));
	mMainMenu.addItem(MenuItem("Affichage",Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f*4.0/3.0),40,NULL));
	mMainMenu.addItem(MenuItem("Retour",Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f*5.0/3.0),40,NULL));
	mMainMenu.setFocused(true);

	//Menu pour la sélection des touches clavier
	mKeyMenu.addItem(MenuItem("Tirer",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*9.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Arme Speciale",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*10.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Droite",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*11.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Gauche",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*12.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Avant",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*13.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Tirer",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*16.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Arme Speciale",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*17.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Gauche",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*18.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Droite",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*19.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Avant",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*20.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Enregistrer",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*21.0/12.0),20,NULL));
	mKeyMenu.addItem(MenuItem("Configuration par defaut",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*22.0/12.0),20,NULL));


	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*9.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.secondary),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*10.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.left),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*11.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.right),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*12.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.forward),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*13.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.primary),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*16.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.secondary),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*17.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.left),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*18.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.right),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*19.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.forward),Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*20.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem("",Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*21.0/12.0),20,NULL));
	mKeyValueMenu.addItem(MenuItem("",Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*22.0/12.0),20,NULL));

}

SettingsMenu::~SettingsMenu()
{
}

void SettingsMenu::enter()
{
	mWindow->setTitle("Candy Saga ~ Configuration ~");
}

void SettingsMenu::leave(){
	mGame->setSettings(mCurrentSettings);	
}

bool SettingsMenu::update(const Real & timeSinceLastFrame){

	if (clock.getElapsedTime().asSeconds() > 0.12)
	{

		// navigation in menu
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (SelectedMenu==MENU1)
			{
				Selected = (Choice)(((int)Selected+3)%4);
			}else{
				switch (Selected)
				{
					case KEYBOARD:
						SelectedKey=(keyMenu)(((int)SelectedKey+11)%12);
						break;
					default:
						break;
				}
			}
			mMainMenu.moveUp();
			mKeyMenu.moveUp();
			mKeyValueMenu.moveUp();
			clock.restart();
		}

		//navigation too
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (SelectedMenu==MENU1)
			{
				Selected = (Choice)(((int)Selected+1)%4);
			}else{
				switch (Selected)
				{
					case KEYBOARD:
						SelectedKey=(keyMenu)(((int)SelectedKey+1)%12);
						break;
					default:
						break;
				}
			}
			mMainMenu.moveDown();
			mKeyMenu.moveDown();
			mKeyValueMenu.moveDown();
			clock.restart();
		}
		bool test=false;
		//tests for changing parameters
		if (((Keyboard::isKeyPressed(Keyboard::Right) && SelectedMenu == MENU1) || Keyboard::isKeyPressed(Keyboard::Return)) && Selected!=RETURN)
		{
			if (SelectedMenu==MENU1)
			{
				Color tmp = menu1Rect.getFillColor();
				menu1Rect.setFillColor(menu2Rect.getFillColor());
				menu2Rect.setFillColor(tmp);
				SelectedMenu=MENU2;
				mMainMenu.setFocused(false);
				mKeyMenu.setFocused(true);
				mKeyValueMenu.setFocused(true);
			}else if(SelectedKey != RESTORE && SelectedKey != SAVE){
				test=true;
			}
			else if(SelectedKey == RESTORE)
			{
				//restore default settings
				mGame->getSettings().loadDefault();
				mCurrentSettings= mGame->getSettings();
				mKeyValueMenu.setToFirst();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.secondary));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.left));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.right));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.forward));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.primary));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.secondary));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.left));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.right));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.forward));
				mKeyValueMenu.moveDown();
				mKeyValueMenu.moveDown();
			}
			else // SAVE
			{
				mGame->getSettings().saveSettings(mCurrentSettings.mBinding1,mCurrentSettings.mBinding2);
			}
		}

		if (test)
		{
			mWindow->draw(keySelectTxt);
			mWindow->display();
			bool fini=false;
			sf::Event event;
			while (mWindow->isOpen() && mWindow->pollEvent(event)){}
			while (!fini)
			{
				while (mWindow->isOpen() && mWindow->pollEvent(event))
				{
					switch (event.type)
					{
						case sf::Event::KeyPressed:
							switch (SelectedKey)
							{
								case PRIMARY1:
									mCurrentSettings.mBinding1.primary=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary));
									fini=true;
									break;
								case SECONDARY1:
									mCurrentSettings.mBinding1.secondary=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.secondary));
									fini=true;
									break;
								case LEFT1:
									mCurrentSettings.mBinding1.left=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.left));
									fini=true;
									break;
								case RIGHT1:
									mCurrentSettings.mBinding1.right=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.right));
									fini=true;
									break;
								case FORWARD1:
									mCurrentSettings.mBinding1.forward=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.forward));
									fini=true;
									break;
								case PRIMARY2:
									mCurrentSettings.mBinding2.primary=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.primary));
									fini=true;
									break;
								case SECONDARY2:
									mCurrentSettings.mBinding2.secondary=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.secondary));
									fini=true;
									break;
								case LEFT2:
									mCurrentSettings.mBinding2.left=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.left));
									fini=true;
									break;
								case RIGHT2:
									mCurrentSettings.mBinding2.right=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.right));
									fini=true;
									break;
								case FORWARD2:
									mCurrentSettings.mBinding2.forward=event.key.code;
									mKeyValueMenu.changeName(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.forward));
									fini=true;
									break;
								default:
									fini=true;
									break;
							}
							break;
						default:
							break;
					}
				}
			}
		}

		if (((Keyboard::isKeyPressed(Keyboard::Escape)) || (Keyboard::isKeyPressed(Keyboard::Left))) && (SelectedMenu==MENU2))
		{
			Color tmp = menu1Rect.getFillColor();
			menu1Rect.setFillColor(menu2Rect.getFillColor());
			menu2Rect.setFillColor(tmp);
			SelectedMenu=MENU1;
			mMainMenu.setFocused(true);
			mKeyMenu.setFocused(false);
			mKeyValueMenu.setFocused(false);
		}
	}

	mWindow->clear();

	mWindow->draw(menu1Rect);
	mWindow->draw(menu2Rect);
	// to change the menu context
	switch (Selected)
	{
		case KEYBOARD:
			mWindow->draw(player1Txt);
			mWindow->draw(player2Txt);
			mKeyMenu.render();
			mKeyValueMenu.render();
			break;
		case VOLUME:
			mWindow->draw(volTxt);
			break;
		case DISPLAY:
			mWindow->draw(dispTxt);
			break;
		default:
			break;
	}

	mWindow->draw(titleTxt);

	mMainMenu.render();

	if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return)) && (Selected == RETURN) && (SelectedMenu == MENU1))
	{
		mWindow->setTitle(mPreviousTitle);
		mGame->changeState(mpreviousState);
		delete this;
	}

	return true;
}
