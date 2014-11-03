#include "CandyPause.h"
#include "CandySettingsMenu.h"
#include "CandyMainMenu.h"

using namespace Candy;
using namespace sf;

Pause::Pause(Game *game, RenderWindow * window,Play * gameSession):
	GameState(game,window),titleTxt("Pause",game->getFont(),100),mMenu(window,game)
{
	mTransparentLayer = RectangleShape(Vector(mWindow->getSize().x,mWindow->getSize().y));
	mTransparentLayer.setFillColor(sf::Color(0,0,0,180));
	sf::FloatRect textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));

	titleTxt.setColor(Color::Red);

	clock.restart();

	Selected = PLAY;
	keySelection = 0;

	mMenu.addItem(MenuItem("Reprendre",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*2.0/3.0),40,NULL));
	mMenu.addItem(MenuItem("Configuration",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f),40,NULL));
	mMenu.addItem(MenuItem("Menu Principal",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*4.0/3.0),40,NULL));
	mMenu.addItem(MenuItem("Quitter",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*5.0/3.0),40,NULL));
	mMenu.setFocused(true);

	mGameSession = gameSession;
}

Pause::~Pause()
{
}

void Pause::enter(){
	mWindow->setTitle("Candy Saga ~Pause~");
	SoundManager::getInstance().fadeIn("MenuMusic");
}
void Pause::leave(){
}

bool Pause::update(const Real & timeSinceLastFrame){
	mWindow->clear();
	mGameSession->update(0);//draw the scene as it was when entering pause
	mWindow->draw(mTransparentLayer);

	mWindow->draw(titleTxt);
	mMenu.render();

	if (!(clock.getElapsedTime().asSeconds() < 0.12))
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			keySelection--;
			mMenu.moveUp();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			keySelection++;
			mMenu.moveDown();
		}
		if (Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::Return))
		{
			switch (Selected)
			{
				case PLAY:
					mWindow->setTitle(mPreviousTitle);
					mGame->changeState(mGameSession);
					SoundManager::getInstance().fadeOut("MenuMusic");
					mGameSession->updateSettings();
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
				Selected = PLAY;
				clock.restart();
				break;
			case 1:
				Selected = SETTINGS;
				clock.restart();
				break;
			case 2:
				Selected = MAINMENU;
				clock.restart();
				break;
			case 3:
				Selected = QUIT;
				clock.restart();
				break;
		}
	}

	return true;
}
