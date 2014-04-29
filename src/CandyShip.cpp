#include "CandyShip.h"
#include "CandyMath.h"
#include "CandyBullet.h"
using namespace Candy;

Ship::Ship(/*Team & owner,*/ unsigned int maxLife) : Actor("Ship",Vector(0,0),new Body(Body::Circle{5}))
{

	// mTeam = Team;
	mMaxLife = maxLife;
	mMaxSpeed=50;
	mPeakTime=1.2;
	
	setTexture(TextureManager::getInstance().getTexture("BlueShip"));
	

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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		move(Vector(timeSinceLastFrame*120,0),TS_LOCAL);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate(-timeSinceLastFrame*300);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotate(timeSinceLastFrame*360);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		mWorld->addActor(new Bullet(getPosition(),getDirectionVector()*1000));
	}
	Actor::update(timeSinceLastFrame);

}
