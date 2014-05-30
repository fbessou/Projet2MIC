#include "CandySettingsMenu.h"
#include <iostream>

using namespace Candy;
using namespace sf;
using namespace std;

SettingsMenu::SettingsMenu(Game * game, RenderWindow * window, GameState * previousState):
  GameState(game,window),mCurrentSettings(game->getSettings()),titleTxt("Parameters",game->getFont(),100),keyboardTxt("Keyboard",game->getFont(),40),player1Txt("Player 1 : ",game->getFont(),30),primary1Txt("Primary Weapon",game->getFont(),20),p1ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary),game->getFont(),20),secondary1Txt("Secondary Weapon",game->getFont(),20),s1ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.secondary),game->getFont(),20),left1Txt("Left",game->getFont(),20),l1ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.left),game->getFont(),20),right1Txt("Right",game->getFont(),20),r1ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.right),game->getFont(),20),forward1Txt("Up",game->getFont(),20),f1ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.forward),game->getFont(),20),player2Txt("Player 2 : ",game->getFont(),30),primary2Txt("Primary Weapon",game->getFont(),20),p2ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.primary),game->getFont(),20),secondary2Txt("Secondary Weapon",game->getFont(),20),s2ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.secondary),game->getFont(),20),left2Txt("Left",game->getFont(),20),l2ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.left),game->getFont(),20),right2Txt("Right",game->getFont(),20),r2ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.right),game->getFont(),20),forward2Txt("Up",game->getFont(),20),f2ValueTxt(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.forward),game->getFont(),20),saveTxt("Save config",game->getFont(),20),restoreTxt("Default",game->getFont(),20),volumeTxt("Volume",game->getFont(),40),volTxt("Not implemented yet",game->getFont(),40),displayTxt("Display",game->getFont(),40),dispTxt("Nor this one",game->getFont(),40),returnTxt("Return",game->getFont(),40)
{
	sf::FloatRect textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));

	textRect = keyboardTxt.getLocalBounds();
	keyboardTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	keyboardTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f*2.0/3.0));
	
	// menu for player 1 's keyboard
	textRect = player1Txt.getLocalBounds();
	player1Txt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	player1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*2.0/3.0));

	textRect = primary1Txt.getLocalBounds();
	primary1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	primary1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*9.0/12.0));

	textRect = p1ValueTxt.getLocalBounds();
	p1ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	p1ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*9.0/12.0));

	textRect = secondary1Txt.getLocalBounds();
	secondary1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	secondary1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*10.0/12.0));

	textRect = s1ValueTxt.getLocalBounds();
	s1ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	s1ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*10.0/12.0));

	textRect = left1Txt.getLocalBounds();
	left1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	left1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*11.0/12.0));

	textRect = l1ValueTxt.getLocalBounds();
	l1ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	l1ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*11.0/12.0));

	textRect = right1Txt.getLocalBounds();
	right1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	right1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*12.0/12.0));

	textRect = r1ValueTxt.getLocalBounds();
	r1ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	r1ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*12.0/12.0));

	textRect = forward1Txt.getLocalBounds();
	forward1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	forward1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*13.0/12.0));

	textRect = f1ValueTxt.getLocalBounds();
	f1ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	f1ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*13.0/12.0));

	textRect = player2Txt.getLocalBounds();
	player2Txt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	player2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*15.0/12.0));

	textRect = primary2Txt.getLocalBounds();
	primary2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	primary2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*16.0/12.0));

	textRect = p2ValueTxt.getLocalBounds();
	p2ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	p2ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*16.0/12.0));

	textRect = secondary2Txt.getLocalBounds();
	secondary2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	secondary2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*17.0/12.0));

	textRect = s2ValueTxt.getLocalBounds();
	s2ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	s2ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*17.0/12.0));

	textRect = left2Txt.getLocalBounds();
	left2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	left2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*18.0/12.0));

	textRect = l2ValueTxt.getLocalBounds();
	l2ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	l2ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*18.0/12.0));
	
	textRect = right2Txt.getLocalBounds();
	right2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	right2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*19.0/12.0));

	textRect = r2ValueTxt.getLocalBounds();
	r2ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	r2ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*19.0/12.0));

	textRect = forward2Txt.getLocalBounds();
	forward2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	forward2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*20.0/12.0));

	textRect = f2ValueTxt.getLocalBounds();
	f2ValueTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	f2ValueTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*7.0/4.0,mWindow->getSize().y/2.0f*20.0/12.0));

	textRect = saveTxt.getLocalBounds();
	saveTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	saveTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*21.0/12.0));

	textRect = restoreTxt.getLocalBounds();
	restoreTxt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	restoreTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*22.0/12.0));

	textRect = volumeTxt.getLocalBounds();
	volumeTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	volumeTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f));

	textRect = volTxt.getLocalBounds();
	volTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	volTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*4.0/3.0,mWindow->getSize().y/2.0f));

	textRect = displayTxt.getLocalBounds();
	displayTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	displayTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f*4.0/3.0));

	textRect = dispTxt.getLocalBounds();
	dispTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	dispTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f*4.0/3.0,mWindow->getSize().y/2.0f));

	textRect = returnTxt.getLocalBounds();
	returnTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	returnTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f/3.0,mWindow->getSize().y/2.0f*5.0/3.0));

	mActiveColor = Color::White;
	mInactiveColor = Color(150,150,150);

	titleTxt.setColor(Color::Red);

	keyboardTxt.setColor(mActiveColor);
	player1Txt.setColor(Color::Green);
	primary1Txt.setColor(mActiveColor);
	p1ValueTxt.setColor(mActiveColor);

	secondary1Txt.setColor(mInactiveColor);
	s1ValueTxt.setColor(mInactiveColor);

	left1Txt.setColor(mInactiveColor);
	l1ValueTxt.setColor(mInactiveColor);

	right1Txt.setColor(mInactiveColor);
	r1ValueTxt.setColor(mInactiveColor);

	forward1Txt.setColor(mInactiveColor);
	f1ValueTxt.setColor(mInactiveColor);

	player2Txt.setColor(Color::Green);
	primary2Txt.setColor(mInactiveColor);
	p2ValueTxt.setColor(mInactiveColor);

	secondary2Txt.setColor(mInactiveColor);
	s2ValueTxt.setColor(mInactiveColor);

	left2Txt.setColor(mInactiveColor);
	l2ValueTxt.setColor(mInactiveColor);

	right2Txt.setColor(mInactiveColor);
	r2ValueTxt.setColor(mInactiveColor);

	forward2Txt.setColor(mInactiveColor);
	f2ValueTxt.setColor(mInactiveColor);

	saveTxt.setColor(mInactiveColor);
	restoreTxt.setColor(mInactiveColor);

	volumeTxt.setColor(mInactiveColor);
	volTxt.setColor(Color::Green);
//	setVolumeTxt.setColor(mActiveColor);
//	setMuteTxt.setColor(mInactiveColor);
//	SelectedVolume = VOLUME;

	displayTxt.setColor(mInactiveColor);
	dispTxt.setColor(Color::Green);

	returnTxt.setColor(mInactiveColor);

	mpreviousState = previousState;

	clock.restart();

	Selected = KEYBOARD;
	SelectedMenu = MENU1;
	SelectedKey = PRIMARY1;
}

SettingsMenu::~SettingsMenu()
{
}

void SettingsMenu::enter()
{
	mWindow->setTitle("Candy Saga ~ Parametres ~");
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
			clock.restart();
		}
		bool test=false;
		//tests for changing parameters
		if (((Keyboard::isKeyPressed(Keyboard::Right) && SelectedMenu == MENU1) || Keyboard::isKeyPressed(Keyboard::Return)) && Selected!=RETURN)
		{
			if (SelectedMenu==MENU1)
			{
				SelectedMenu=MENU2;
			}else if(SelectedKey != RESTORE){
				test=true;
			}
			else
			{
				mGame->getSettings().loadDefault();
				mCurrentSettings= mGame->getSettings();
				p1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary));
				s1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.secondary));
				l1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.left));
				r1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.right));
				f1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.forward));
				p2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.primary));
				s2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.secondary));
				l2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.left));
				r2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.right));
				f2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.forward));
				cout<<mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary)<<endl;
			}
		}

		if (test)
		{
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
									p1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.primary));
									fini=true;
									break;
								case SECONDARY1:
									mCurrentSettings.mBinding1.secondary=event.key.code;
									s1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.secondary));
									fini=true;
									break;
								case LEFT1:
									mCurrentSettings.mBinding1.left=event.key.code;
									l1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.left));
									fini=true;
									break;
								case RIGHT1:
									mCurrentSettings.mBinding1.right=event.key.code;
									r1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.right));
									fini=true;
									break;
								case FORWARD1:
									mCurrentSettings.mBinding1.forward=event.key.code;
									f1ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding1.forward));
									fini=true;
									break;
								case PRIMARY2:
									mCurrentSettings.mBinding2.primary=event.key.code;
									p2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.primary));
									fini=true;
									break;
								case SECONDARY2:
									mCurrentSettings.mBinding2.secondary=event.key.code;
									s2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.secondary));
									fini=true;
									break;
								case LEFT2:
									mCurrentSettings.mBinding2.left=event.key.code;
									l2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.left));
									fini=true;
									break;
								case RIGHT2:
									mCurrentSettings.mBinding2.right=event.key.code;
									r2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.right));
									fini=true;
									break;
								case FORWARD2:
									mCurrentSettings.mBinding2.forward=event.key.code;
									f2ValueTxt.setString(mCurrentSettings.keyToString(mCurrentSettings.mBinding2.forward));
									fini=true;
									break;
								case SAVE:
									mGame->getSettings().saveSettings(mCurrentSettings.mBinding1,mCurrentSettings.mBinding2);
									fini=true;
									break;
								case RESTORE:
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
			SelectedMenu=MENU1;
		}
	}

	// to change the color of the selection
	switch (Selected)
	{
		case KEYBOARD:
			keyboardTxt.setColor(mActiveColor);
			volumeTxt.setColor(mInactiveColor);
			displayTxt.setColor(mInactiveColor);
			returnTxt.setColor(mInactiveColor);
			break;
		case VOLUME:
			keyboardTxt.setColor(mInactiveColor);
			volumeTxt.setColor(mActiveColor);
			displayTxt.setColor(mInactiveColor);
			returnTxt.setColor(mInactiveColor);
			break;
		case DISPLAY:
			keyboardTxt.setColor(mInactiveColor);
			volumeTxt.setColor(mInactiveColor);
			displayTxt.setColor(mActiveColor);
			returnTxt.setColor(mInactiveColor);
			break;
		case RETURN:
			keyboardTxt.setColor(mInactiveColor);
			volumeTxt.setColor(mInactiveColor);
			displayTxt.setColor(mInactiveColor);
			returnTxt.setColor(mActiveColor);
			break;
	}

	switch (SelectedKey)
	{
		case PRIMARY1:
			primary1Txt.setColor(mActiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mActiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case SECONDARY1:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mActiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mActiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case LEFT1:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mActiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mActiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case RIGHT1:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mActiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mActiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case FORWARD1:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mActiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mActiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case PRIMARY2:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mActiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mActiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case SECONDARY2:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mActiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mActiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case LEFT2:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mActiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mActiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case RIGHT2:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mActiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mActiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case FORWARD2:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mActiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mActiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case SAVE:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mActiveColor);
			restoreTxt.setColor(mInactiveColor);
			break;
		case RESTORE:
			primary1Txt.setColor(mInactiveColor);
			secondary1Txt.setColor(mInactiveColor);
			left1Txt.setColor(mInactiveColor);
			right1Txt.setColor(mInactiveColor);
			forward1Txt.setColor(mInactiveColor);
			primary2Txt.setColor(mInactiveColor);
			secondary2Txt.setColor(mInactiveColor);
			left2Txt.setColor(mInactiveColor);
			right2Txt.setColor(mInactiveColor);
			forward2Txt.setColor(mInactiveColor);
			p1ValueTxt.setColor(mInactiveColor);
			s1ValueTxt.setColor(mInactiveColor);
			l1ValueTxt.setColor(mInactiveColor);
			r1ValueTxt.setColor(mInactiveColor);
			f1ValueTxt.setColor(mInactiveColor);
			p2ValueTxt.setColor(mInactiveColor);
			s2ValueTxt.setColor(mInactiveColor);
			l2ValueTxt.setColor(mInactiveColor);
			r2ValueTxt.setColor(mInactiveColor);
			f2ValueTxt.setColor(mInactiveColor);
			saveTxt.setColor(mInactiveColor);
			restoreTxt.setColor(mActiveColor);
			break;
	}

	mWindow->clear();

	// to change the menu context
	switch (Selected)
	{
		case KEYBOARD:
			mWindow->draw(player1Txt);
			mWindow->draw(primary1Txt);
			mWindow->draw(p1ValueTxt);
			mWindow->draw(secondary1Txt);
			mWindow->draw(s1ValueTxt);
			mWindow->draw(left1Txt);
			mWindow->draw(l1ValueTxt);
			mWindow->draw(right1Txt);
			mWindow->draw(r1ValueTxt);
			mWindow->draw(forward1Txt);
			mWindow->draw(f1ValueTxt);
			mWindow->draw(player2Txt);
			mWindow->draw(primary2Txt);
			mWindow->draw(p2ValueTxt);
			mWindow->draw(secondary2Txt);
			mWindow->draw(s2ValueTxt);
			mWindow->draw(left2Txt);
			mWindow->draw(l2ValueTxt);
			mWindow->draw(right2Txt);
			mWindow->draw(r2ValueTxt);
			mWindow->draw(forward2Txt);
			mWindow->draw(f2ValueTxt);
			mWindow->draw(saveTxt);
			mWindow->draw(restoreTxt);
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
	mWindow->draw(keyboardTxt);
	mWindow->draw(volumeTxt);
	mWindow->draw(displayTxt);
	mWindow->draw(returnTxt);

	if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return)) && (Selected == RETURN) && (SelectedMenu == MENU1))
	{
		mWindow->setTitle(mPreviousTitle);
		mGame->changeState(mpreviousState);
		delete this;
	}

	return true;
}
