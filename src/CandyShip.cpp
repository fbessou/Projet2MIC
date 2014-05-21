#include "CandyShip.h"
#include "CandyMath.h"
#include "CandyBullet.h"
#include <iostream>
#include "CandyBasicWeapon.h"

using namespace Candy;
using namespace std;

Body * createShipBody()
{
	Body::ConvexHull hull;
	hull.relativeList.push_back(Vector(32,0));
	hull.relativeList.push_back(Vector(0,32));
	hull.relativeList.push_back(Vector(-32,0));
	hull.relativeList.push_back(Vector(0,-32));
	return new Body(hull); 
}

Ship::Ship(Team * owner, unsigned int maxLife) : Actor("Ship",owner->shipBase,createShipBody(),Vector(0,0),SHIP_LAYER),mPrimaryWeapon(nullptr),mSecondaryWeapon(nullptr)

{
	mTeam = owner;
	mLife=maxLife;
	mMaxLife = maxLife;
	mMaxSpeed=50;
	mPeakTime=1.2;
	
	setTexture(TextureManager::getInstance().getTexture("BlueShip"));
	setPosition(mTeam->shipBase);
	Real rotation = Math::atan2(mTeam->direction.y,mTeam->direction.x);
	rotate(rotation,Math::RADIAN);
	setPrimaryWeapon(new BasicWeapon(this));
	

}

Ship::~Ship()
{
	if(mSecondaryWeapon != nullptr)
		delete mSecondaryWeapon;
	delete mPrimaryWeapon;
	delete mTexture;
}

void Ship::setLife(unsigned int life)
{
	mLife = Math::clamp(life,0,mMaxLife);
}

unsigned int Ship::getLife() const
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
	Vector relPosition = getBaseRelativePosition();
	if(sf::Keyboard::isKeyPressed(mTeam->keys.forward))
	{
		move(Vector(timeSinceLastFrame*200,0),TS_LOCAL);
		mVelocity=Vector(0,0);
	}
	else
	{
		if(dot(getPosition() - mTeam->shipBase,mTeam->direction)>0)
			mVelocity=-(((Math::clamp(relPosition.x,0.,1000.)+100)*2)*mTeam->direction);
		else
			mVelocity=Vector(0,0);
	}

	if(sf::Keyboard::isKeyPressed(mTeam->keys.right))
	{
		move(Vector(0,timeSinceLastFrame*400),TS_LOCAL);
		//rotate(-timeSinceLastFrame*360);
	}
	else if(sf::Keyboard::isKeyPressed(mTeam->keys.left))
	{
		move(Vector(0,-timeSinceLastFrame*400),TS_LOCAL);
		//rotate(timeSinceLastFrame*360);
	}

	if(sf::Keyboard::isKeyPressed(mTeam->keys.primary))
	{
		mPrimaryWeapon->tryFiring(timeSinceLastFrame);
	}
	if(mSecondaryWeapon!= nullptr && sf::Keyboard::isKeyPressed(mTeam->keys.secondary))
	{
		mSecondaryWeapon->tryFiring(timeSinceLastFrame);
	}

	Actor::update(timeSinceLastFrame);
	return true;
}
void Ship::setPrimaryWeapon(Weapon * weapon)
{
	if(mPrimaryWeapon != nullptr)
		delete mPrimaryWeapon;
	mPrimaryWeapon = weapon;
}

void Ship::setSecondaryWeapon(Weapon * weapon)
{
	if(mSecondaryWeapon != nullptr)
		delete mSecondaryWeapon;
	mSecondaryWeapon = weapon;
}

Vector Ship::getBaseRelativePosition() const 
{
	Vector diff =  getPosition() - mTeam->shipBase;
	return Vector(dot(diff,mTeam->direction),dot(diff,mTeam->direction.directOrthogonal()));
}

void Ship::onCollision( Actor * actor)
{
	if(actor->getType()=="Bullet")
		mLife-=Math::clamp(2,0,mLife);
	else
		cout<<"I'm not a bullet"<<endl;
		
}
