#include "CandyPause.h"
#include "CandySettingsMenu.h"
#include "CandyMainMenu.h"

using namespace Candy;
using namespace sf;
using namespace std;

Pause::Pause(Game *game, RenderWindow * window,Play * gameSession):
	GameState(game,window),mMenu(window,game),titleTxt("Pause",game->getFont(),100),returnTxt("Reprendre",game->getFont(),40),paramTxt("Configuration",game->getFont(),40),exitGameTxt("Menu principal",game->getFont(),40),quitAppTxt("Quitter",game->getFont(),40)
{

	mActiveColor=Color::White;
	mInactiveColor=Color(150,150,150);
	mDisabledColor=Color(90,90,90);

	mMenu.addItem(MenuItem("Reprendre",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*2.0/3.0),40,NULL));
	mMenu.addItem(MenuItem("Configuration",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f),40,NULL));
	mMenu.addItem(MenuItem("Menu Principal",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*4.0/3.0),40,NULL));
	mMenu.addItem(MenuItem("Quitter",Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f*5.0/3.0),40,NULL));

	mMenu.setFocused(true);


	mTransparentLayer = RectangleShape(Vector(mWindow->getSize().x,mWindow->getSize().y));
	mTransparentLayer.setFillColor(sf::Color(0,0,0,180));

	sf::FloatRect textRect = titleTxt.getLocalBounds();
	titleTxt.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
	titleTxt.setPosition(Vector2f(mWindow->getSize().x/2.0f,mWindow->getSize().y/2.0f/3.0));
	titleTxt.setColor(Color::Red);

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
	SoundManager::getInstance().fadeIn("MenuMusic");
}
void Pause::leave(){
}

bool Pause::update(const Real & timeSinceLastFrame){

	if (clock.getElapsedTime().asSeconds() > 0.12)
	{
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			mMenu.moveUp();
			keySelection--;
			clock.restart();
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			mMenu.moveDown();
			keySelection++;
			clock.restart();
		}
	}

	keySelection = keySelection>=0 ? keySelection%4 : 3;

	switch (keySelection)
	{
		case 0:
			Selected = PLAY;
			break;
		case 1:
			Selected = SETTINGS;
			break;
		case 2:
			Selected = MAINMENU;
			break;
		case 3:
			Selected = QUIT;
			break;
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

	mWindow->clear();
	mGameSession->update(0);//draw the scene as it was when entering pause
	mWindow->draw(mTransparentLayer);
	mMenu.render();
	mWindow->draw(titleTxt);



	return true;
}
