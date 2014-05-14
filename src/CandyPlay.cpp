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
	//TODO charger le KeyBinding de la config plutot qu'en dur
	KeyBinding bindingTeam1{sf::Keyboard::LShift,
							sf::Keyboard::Q,
							sf::Keyboard::A,
							sf::Keyboard::D,
							sf::Keyboard::Z,
							};

	KeyBinding bindingTeam2{sf::Keyboard::Space,
							sf::Keyboard::M,
							sf::Keyboard::K,
							sf::Keyboard::P,
							sf::Keyboard::O,
							};
	/*On cree chaque equipe*/
	mTeam1 = new Team(Vector(100,300),Vector::UNIT_X,bindingTeam1);
	mTeam2 = new Team(Vector(700,300),-Vector::UNIT_X,bindingTeam2);
	/*On rajoute les vaisseaux*/

	mWorld.addActor(new Ship(mTeam1,100));
	mWorld.addActor(new Ship(mTeam2,100));
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
