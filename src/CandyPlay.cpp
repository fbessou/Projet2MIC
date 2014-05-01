#include "CandyPlay.h"
#include "CandyPause.h"
#include "CandyShip.h"
#include "CandyBonus.h"
#include "CandyWorld.h"


using namespace Candy;
using namespace sf;

Play::Play(Game * game, RenderWindow * window):
	GameState(game,window),mWorld(window)
{
	mBackground.setTexture(TextureManager::getInstance().getTexture("NightSky"));
	mBackground.setTextureRect(IntRect(0,0,800,600));
	mWorld.addActor(new Ship(100));
}

Play::~Play(){}

void Play::enter(){
	mWindow->setTitle("Candy Saga 3 Le Retour des Caries ~The Main Game~");
}

void Play::leave(){}

bool Play::update(const Real & timeSinceLastFrame){

	mWindow->clear();

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		mGame->changeState(new Pause(mGame,mWindow,this));
	}
	else if(Keyboard::isKeyPressed(Keyboard::A))
	{
		auto func = Math::IntURNG::randomByte;
		mWorld.addActor(new Bonus(Vector(func(),func()),sf::Color((*func)(),(*func)(),(*func)(),255)));
	}
	mWorld.step(timeSinceLastFrame);
	mWindow->draw(mBackground);
	mWorld.render();

	return true;
}
