#include "CandyPlay.h"
#include "CandyPause.h"
#include "CandyShip.h"
#include "CandyBonus.h"
#include "CandyWorld.h"


using namespace Candy;
using namespace sf;

Play::Play(Game * game, RenderWindow * window):
	GameState(game,window),mWorld(window),mClock(0)
{
	/* On met une jolie texture de ciel etoile*/
	mBackground.setTexture(TextureManager::getInstance().getTexture("NightSky"));
	mBackground.setTextureRect(IntRect(0,0,800,600));

	/*On cree chaque equipe*/
	mTeam1 = new Team(sf::Color::Red,Vector(400,50),Vector::UNIT_Y,game->getSettings().mBinding1);
	mTeam2 = new Team(sf::Color(100,200,255,255),Vector(400,550),-Vector::UNIT_Y,game->getSettings().mBinding2);
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
	auto rect = mBackground.getTextureRect();
	rect.left= 1000*sin(mClock/5);
	rect.top = 10000*sin(mClock/50);
	mBackground.setTextureRect(rect);
	

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
	//On affiche la scene
	mWorld.render();
	//On affiche les overlays
	showOverlays();

	if(mTeam1->getShip()->getLife()==0)
		1;
		//std::cout<<"Team 2 win"<<std::endl;
	else if(mTeam2->getShip()->getLife()==0)
		2;
		//std::cout<<"Team 1 win"<<std::endl;
	return true;
}

void Play::onLostFocus()
{
		mGame->changeState(new Pause(mGame,mWindow,this));
}
