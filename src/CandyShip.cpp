#include "CandyShip.h"
#include "CandyMath.h"
#include <iostream>
using namespace Candy;

Ship::Ship(/*Team & owner,*/ unsigned int maxLife) : Actor("Ship",Vector(0,0))
{

	// mTeam = Team;
	mMaxLife = maxLife;
	sf::Texture * mTexture = new sf::Texture;
	mTexture->loadFromFile("media/test.png");
	mTexture->setSmooth(true);
	sf::Sprite * sprite = new sf::Sprite();
	sprite->setTexture(*mTexture);
	setSprite(sprite);
	

}

Ship::~Ship()
{
	delete mTexture;
}

void Ship::setLife(unsigned int life)
{
	mLife = Math::clamp(life,0,mMaxLife);
}

unsigned int Ship::getLife()
{
	return mLife;
}

void Ship::setMaxLife(unsigned int newMax)
{
	mMaxLife = newMax;
}

void Ship::update(const Real & timeSinceLastFrame)
{
	Actor::update(timeSinceLastFrame);
	std::cout.setf( std::ios::fixed, std:: ios::floatfield );
	std::cout<<timeSinceLastFrame<<std::endl;
	setPosition(getPosition()+Vector(100.00*timeSinceLastFrame,0));
}
