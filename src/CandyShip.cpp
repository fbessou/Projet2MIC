#include "CandyShip.h"
#include "CandyMath.h"
using namespace Candy;

Ship::Ship(/*Team & owner,*/ unsigned int maxLife) : Actor("Ship",Vector(0,0),new Body(Body::Circle{5}))
{

	// mTeam = Team;
	mMaxLife = maxLife;
	sf::Sprite * sprite = new sf::Sprite();
	sprite->setTexture(TextureManager::getInstance().getTexture("BlueShip"));
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

void Ship::forwardImpulse()
{
	
}

void Ship::setMaxLife(unsigned int newMax)
{
	mMaxLife = newMax;
}

void Ship::update(const Real & timeSinceLastFrame)
{
	Actor::update(timeSinceLastFrame);
	setPosition(getPosition()+Vector(100.00*timeSinceLastFrame,0));
}
