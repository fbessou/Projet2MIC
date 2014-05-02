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
	/* On met une jolie texture de ciel etoile*/
	mBackground.setTexture(TextureManager::getInstance().getTexture("NightSky"));
	mBackground.setTextureRect(IntRect(0,0,800,600));
	/*On rajoute un vaisseau*/
	mWorld.addActor(new Ship(100));
}

Play::~Play(){}

void Play::enter(){
	/* On redefini le titre */
	mWindow->setTitle("Candy Saga");
}

void Play::leave(){}

bool Play::update(const Real & timeSinceLastFrame){
	if(timeSinceLastFrame!=0)
	{
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
	}
	mWindow->draw(mBackground);
	mWorld.render();

	return true;
}

void Play::onLostFocus()
{
		mGame->changeState(new Pause(mGame,mWindow,this));
}
