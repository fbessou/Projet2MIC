#include "CandySettingsMenu.h"

using namespace Candy;
using namespace sf;


SettingsMenu::SettingsMenu(Game * game, RenderWindow * window, GameState * previousState):
  GameState(game,window),titleTxt("Parameters",game->getFont(),100),keyboardTxt("Keyboard",game->getFont(),40),player1Txt("Player 1 : ",game->getFont(),30),primary1Txt("Primary Weapon",game->getFont(),20),secondary1Txt("Secondary Weapon",game->getFont(),20),left1Txt("Left",game->getFont(),20),right1Txt("Right",game->getFont(),20),forward1Txt("Up",game->getFont(),20),player2Txt("Player 2 : ",game->getFont(),30),primary2Txt("Primary Weapon",game->getFont(),20),secondary2Txt("Secondary Weapon",game->getFont(),20),left2Txt("Left",game->getFont(),20),right2Txt("Right",game->getFont(),20),forward2Txt("Up",game->getFont(),20),volumeTxt("Volume",game->getFont(),40),volTxt("Not implemented yet",game->getFont(),40),displayTxt("Display",game->getFont(),40),dispTxt("Nor this one",game->getFont(),40),returnTxt("Return",game->getFont(),40)
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
	primary1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*10.0/12.0));

	textRect = secondary1Txt.getLocalBounds();
	secondary1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	secondary1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*11.0/12.0));

	textRect = left1Txt.getLocalBounds();
	left1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	left1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*12.0/12.0));

	textRect = right1Txt.getLocalBounds();
	right1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	right1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*13.0/12.0));

	textRect = forward1Txt.getLocalBounds();
	forward1Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	forward1Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*14.0/12.0));

	textRect = player2Txt.getLocalBounds();
	player2Txt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	player2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*16.0/12.0));

	textRect = primary2Txt.getLocalBounds();
	primary2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	primary2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*18.0/12.0));

	textRect = secondary2Txt.getLocalBounds();
	secondary2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	secondary2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*19.0/12.0));

	textRect = left2Txt.getLocalBounds();
	left2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	left2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*20.0/12.0));

	textRect = right2Txt.getLocalBounds();
	right2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	right2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*21.0/12.0));

	textRect = forward2Txt.getLocalBounds();
	forward2Txt.setOrigin(textRect.left,textRect.top+textRect.height/2.0f);
	forward2Txt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*22.0/12.0));

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
	secondary1Txt.setColor(mInactiveColor);
	left1Txt.setColor(mInactiveColor);
	right1Txt.setColor(mInactiveColor);
	forward1Txt.setColor(mInactiveColor);
	player2Txt.setColor(Color::Green);
	primary2Txt.setColor(mInactiveColor);
	secondary2Txt.setColor(mInactiveColor);
	left2Txt.setColor(mInactiveColor);
	right2Txt.setColor(mInactiveColor);
	forward2Txt.setColor(mInactiveColor);

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

void SettingsMenu::leave(){}

bool SettingsMenu::update(const Real & timeSinceLastFrame){

	if (clock.getElapsedTime().asSeconds() > 0.12)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (SelectedMenu==MENU1)
			{
				Selected = (Choice)(((int)Selected+3)%4);
			}else{
				switch (Selected)
				{
					case KEYBOARD:
						SelectedKey=(keyMenu)(((int)SelectedKey+9)%10);
					default:
						break;
				}
			}
			clock.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (SelectedMenu==MENU1)
			{
				Selected = (Choice)(((int)Selected+1)%4);
			}else{
				switch (Selected)
				{
					case KEYBOARD:
						SelectedKey=(keyMenu)(((int)SelectedKey+1)%10);;
						break;
					default:
						break;
				}
			}
			clock.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right) || ((Keyboard::isKeyPressed(Keyboard::Return) || Keyboard::isKeyPressed(Keyboard::Space) ) && (Selected!=RETURN)))
		{
			if (SelectedMenu==MENU1)
			{
				SelectedMenu=MENU2;
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
			break;
	}

	mWindow->clear();

	// to change the menu context
	switch (Selected)
	{
		case KEYBOARD:
			mWindow->draw(player1Txt);
			mWindow->draw(primary1Txt);
			mWindow->draw(secondary1Txt);
			mWindow->draw(left1Txt);
			mWindow->draw(right1Txt);
			mWindow->draw(forward1Txt);
			mWindow->draw(player2Txt);
			mWindow->draw(primary2Txt);
			mWindow->draw(secondary2Txt);
			mWindow->draw(left2Txt);
			mWindow->draw(right2Txt);
			mWindow->draw(forward2Txt);
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
