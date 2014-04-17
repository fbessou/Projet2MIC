#include "CandyShip.h"
#include "CandyMath.h"
#include <iostream>
using namespace Candy;

Ship::Ship(/*Team & owner,*/ unsigned int maxLife) : Actor("Ship",Vector(0,0))
{

	// mTeam = Team;
	mMaxLife = maxLife;
	sf::Texture * mTexture = new sf::Texture;
	mTexture->loadFromFile("media/tes.png");
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

void Ship::update(unsigned int t)
{
	Actor::update(t);
	setPosition(getPosition()+Vector(0.01,0));
}
