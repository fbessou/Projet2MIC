#include "CandyPlay.h"
#include "CandyPause.h"
#include "CandyShip.h"
#include "CandyBonus.h"
#include "CandyWorld.h"
#include "CandyAsteroid.h"

using namespace Candy;
using namespace sf;

Play::Play(Game * game, RenderWindow * window):
	GameState(game,window),mNextAsteroidPopDate(2),mWorld(window),mClock(0)
{
	
	/* On met une jolie texture de ciel etoile*/
	mBackground.setTexture(TextureManager::getInstance().getTexture("NightSky"));
	mBackground.setTextureRect(IntRect(0,0,800,600));

	/*On cree chaque equipe*/
	mTeam1 = new Team(sf::Color::Red,Vector(400,50),Vector::UNIT_Y,game->getSettings().mBinding1);
	mTeam2 = new Team(sf::Color(0,255,255,255),Vector(400,550),-Vector::UNIT_Y,game->getSettings().mBinding2);
	/*On rajoute les vaisseaux*/
	
	mWorld.addActor( mTeam1->getShip());
	mWorld.addActor( mTeam2->getShip());
}

Play::~Play(){
delete mTeam1;
delete mTeam2;
}

void Play::enter(){
	/* On redefini le titre */
	mWindow->setTitle("Candy Saga");
}

void Play::leave(){}

void Play::showOverlays() const
{
	mWindow->draw(mTeam1->getShip()->getLifeBar());
	mWindow->draw(mTeam2->getShip()->getLifeBar());
}

bool Play::update(const Real & timeSinceLastFrame)
{
	mClock+=timeSinceLastFrame;
	//update background
	auto rect = mBackground.getTextureRect();
	rect.left= 1000*sin(mClock/5);
	rect.top = 10000*sin(mClock/50);
	mBackground.setTextureRect(rect);

	//update only if we are not in pause state
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
		else
		{
		//update logic
		asteroidGeneration(timeSinceLastFrame);
		}
		mWorld.step(timeSinceLastFrame);
	}
	mWindow->draw(mBackground);
	//On affiche la scene
	mWorld.render();
	//On affiche les overlays
	showOverlays();

	if(mTeam1->getShip()->getLife()==0)
		mClock+=0;
	//std::cout<<"Team 2 win"<<std::endl;
	else if(mTeam2->getShip()->getLife()==0)
		mClock+=0;
	//std::cout<<"Team 1 win"<<std::endl;
	return true;
}

void Play::onLostFocus()
{
	mGame->changeState(new Pause(mGame,mWindow,this));
}

void Play::asteroidGeneration(const Real & timeSinceLastFrame)
{
	if(mClock>mNextAsteroidPopDate)
	{
		bool screenPart = Math::IntURNG::randomByte()%2;
		
		Vector w = mWindow->getSize();
		Vector pos = Vector(Math::RealURNG::normalised()*50,
						Math::RealURNG::normalised()*400-200);
		pos+=Vector(0,w.y/2);
		Vector velocity;
		if(screenPart)
		{
			pos-=Vector(50,0);
			velocity=Vector(50,0);
		}else
		{
			pos+=Vector(w.x,0);
			velocity=Vector(-50,0);
		}
		mWorld.addActor(new Asteroid(&mWorld,pos,velocity));
		mNextAsteroidPopDate=mClock+Math::RealURNG::normalised()*5;
	}

}
