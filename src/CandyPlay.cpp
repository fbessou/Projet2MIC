#include "CandyPlay.h"
#include "CandyPause.h"

using namespace Candy;
using namespace sf;

Play::Play(Game * game, RenderWindow * window):
	GameState(game,window)
{
}

Play::~Play(){}

void Play::enter(){
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries ~The Main Game~");
}
void Play::leave(){}

bool Play::update(){
	mWindow->clear();

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		mGame->changeState(new Pause(mGame,mWindow,this));
	}

	return true;
}
