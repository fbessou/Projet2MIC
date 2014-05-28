#include "CandyPause.h"
#include "CandySettingsMenu.h"
#include "CandyMainMenu.h"

using namespace Candy;
using namespace sf;

Pause::Pause(Game *game, RenderWindow * window,Play * gameSession):
	GameState(game,window),titleTxt("Pause",game->getFont(),100),returnTxt("Go back playing",game->getFont(),40),paramTxt("Parameters",game->getFont(),40),exitGameTxt("Retourner au menu principal",game->getFont(),40),quitAppTxt("See you later",game->getFont(),40)
{

	mActiveColor=Color::White;
	mInactiveColor=Color(150,150,150);
	mDisabledColor=Color(90,90,90);

	mTransparentLayer = RectangleShape(Vector(mWindow->getSize().x,mWindow->getSize().y));
	mTransparentLayer.setFillColor(sf::Color(0,0,0,125));
	sf::FloatRect textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));

	textRect = returnTxt.getLocalBounds();
	returnTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	returnTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*2.0/3.0));

	textRect = paramTxt.getLocalBounds();
	paramTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	paramTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f));

	textRect = exitGameTxt.getLocalBounds();
	exitGameTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	exitGameTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*4.0/3.0));

	textRect = quitAppTxt.getLocalBounds();
	quitAppTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	quitAppTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*5.0/3.0));

	titleTxt.setColor(Color::Red);
	returnTxt.setColor(mActiveColor);

	clock.restart();

	Selected = PLAY;
	keySelection = 0;

	mGameSession = gameSession;
}

Pause::~Pause()
{
}

void Pause::enter(){
	mWindow->setTitle("Candy Saga ~Pause~");
}
void Pause::leave(){
	mGameSession->updateSettings();
}

bool Pause::update(const Real & timeSinceLastFrame){
	mWindow->clear();
	mGameSession->update(0);//draw the scene as it was when entering pause
	mWindow->draw(mTransparentLayer);

	mWindow->draw(returnTxt);
	mWindow->draw(paramTxt);
	mWindow->draw(exitGameTxt);
	mWindow->draw(quitAppTxt);
	mWindow->draw(titleTxt);

	if (!(clock.getElapsedTime().asSeconds() < 0.12))
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
			keySelection--;
		if (Keyboard::isKeyPressed(Keyboard::Down))
			keySelection++;
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return))
		{
			switch (Selected)
			{
				case PLAY:
					mWindow->setTitle(mPreviousTitle);
					mGame->changeState(mGameSession);
					break;
				case SETTINGS:
					mGame->changeState(new SettingsMenu(mGame, mWindow,this));
					break;
					//should erase gameSession before quitting
				case MAINMENU:
					delete mGameSession;
					mGame->changeState(new MainMenu(mGame,mWindow));
					break;
					//here as well
				case QUIT:
					mGame->quit();
					break;
			}
		}
	}

	keySelection = keySelection>=0 ? keySelection%4 : 3;

	if (clock.getElapsedTime().asSeconds() > 0.12)
	{
		switch (keySelection)
		{
			case 0:
				returnTxt.setColor(mActiveColor);
				paramTxt.setColor(mInactiveColor);
				exitGameTxt.setColor(mInactiveColor);
				quitAppTxt.setColor(mInactiveColor);
				Selected = PLAY;
				clock.restart();
				break;
			case 1:
				returnTxt.setColor(mInactiveColor);
				paramTxt.setColor(mActiveColor);
				exitGameTxt.setColor(mInactiveColor);
				quitAppTxt.setColor(mInactiveColor);
				Selected = SETTINGS;
				clock.restart();
				break;
			case 2:
				returnTxt.setColor(mInactiveColor);
				paramTxt.setColor(mInactiveColor);
				exitGameTxt.setColor(mActiveColor);
				quitAppTxt.setColor(mInactiveColor);
				Selected = MAINMENU;
				clock.restart();
				break;
			case 3:
				returnTxt.setColor(mInactiveColor);
				paramTxt.setColor(mInactiveColor);
				exitGameTxt.setColor(mInactiveColor);
				quitAppTxt.setColor(mActiveColor);
				Selected = QUIT;
				clock.restart();
				break;
		}
	}

	return true;
}
