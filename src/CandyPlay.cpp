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
	//TODO charger le KeyBinding de la config plutot qu'en dur
	KeyBinding bindingTeam1{sf::Keyboard::C,
							sf::Keyboard::V,
							sf::Keyboard::D,
							sf::Keyboard::Q,
							sf::Keyboard::S
							};
	KeyBinding bindingTeam2{sf::Keyboard::RShift,
							sf::Keyboard::LSystem,
							sf::Keyboard::Left,
							sf::Keyboard::Right,
							sf::Keyboard::Up,
							};

	/*On cree chaque equipe*/
	mTeam1 = new Team(Vector(400,100),Vector::UNIT_Y,bindingTeam1);
	mTeam2 = new Team(Vector(400,500),-Vector::UNIT_Y,bindingTeam2);
	/*On rajoute les vaisseaux*/

	mWorld.addActor(mShip1 = new Ship(mTeam1,100));
	mWorld.addActor(mShip2 = new Ship(mTeam2,100));
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
	mWorld.render();

	if(mShip1->getLife()==0)
		std::cout<<"Team 2 win"<<std::endl;
	else if(mShip2->getLife()==0)
		std::cout<<"Team 1 win"<<std::endl;
	return true;
}

void Play::onLostFocus()
{
		mGame->changeState(new Pause(mGame,mWindow,this));
}
