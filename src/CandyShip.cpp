#include "CandyShip.h"
#include "CandyMath.h"
#include "CandyBullet.h"
using namespace Candy;

Ship::Ship(Team * owner, unsigned int maxLife) : Actor("Ship",Vector(0,0),new Body(Body::Circle{32})),mLateralDirection()
{

	mTeam = owner;
	mMaxLife = maxLife;
	mMaxSpeed=50;
	mPeakTime=1.2;
	
	setTexture(TextureManager::getInstance().getTexture("BlueShip"));
	setPosition(mTeam->shipBase);
	Real rotation = Math::atan2(mTeam->direction.y,mTeam->direction.x);
	rotate(rotation,Math::RADIAN);
	

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

bool Ship::update(const Real & timeSinceLastFrame)
{
	if(sf::Keyboard::isKeyPressed(mTeam->keys.forward))
	{
		move(Vector(timeSinceLastFrame*200,0),TS_LOCAL);
	}
	if(sf::Keyboard::isKeyPressed(mTeam->keys.right))
	{
		move(Vector(0,timeSinceLastFrame*250),TS_LOCAL);
		//rotate(-timeSinceLastFrame*360);
	}
	else if(sf::Keyboard::isKeyPressed(mTeam->keys.left))
	{
		move(Vector(0,-timeSinceLastFrame*250),TS_LOCAL);
		//rotate(timeSinceLastFrame*360);
	}

	if(sf::Keyboard::isKeyPressed(mTeam->keys.primary))
	{
		mWorld->addActor(new Bullet(getPosition(),getDirectionVector()*1000));
	}
	Actor::update(timeSinceLastFrame);
	return true;
}
