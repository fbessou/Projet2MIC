#include "CandyTextureManager.h"
#include "CandyBody.h"
#include "CandyMath.h"
#include "CandyShip.h"
#include "CandyTeam.h"
#include "CandyBasicWeapon.h"
#include "CandyBullet.h"
#include "CandyWorld.h"
#include <iostream>

using namespace Candy;
using namespace std;

Body * createShipBody()
{
	Body::ConvexHull hull;
	hull.addPoint(Vector(0,32));
	hull.addPoint(Vector(32,0));
	hull.addPoint(Vector(0,-32));
	hull.addPoint(Vector(-32,0));
	//return new Body(Body::Circle{32}); 
	return new Body(hull); 
}

Ship::Ship(Team * owner, unsigned int maxLife) : Actor("Ship",owner->shipBase,createShipBody(),Vector(0,0),SHIP_LAYER),mPrimaryWeapon(nullptr),mSecondaryWeapon(nullptr),mLifeBar(sf::Color(0,255,0,125),sf::Color(255,0,0,125),{50,5},1)

{
	mTeam = owner;
	mLife=maxLife;
	mMaxLife = maxLife;
	mMaxSpeed=200;
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
}

void Ship::setLife(unsigned int life)
{
	mLife = Math::clamp(life,0.,mMaxLife);
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
	Vector startPosition = getPosition();
	if(sf::Keyboard::isKeyPressed(mTeam->keys.forward) && relPosition.x < 150)
	{
		move(Vector(timeSinceLastFrame*mMaxSpeed*(150.-relPosition.x)/150,0),TS_LOCAL);
		mVelocity=Vector(0,0);
	}
	else
	{
		if(dot(getPosition() - mTeam->shipBase,mTeam->direction)>0)
			mVelocity=-(((Math::clamp(relPosition.x,0.,1000.)+100)*2)*mTeam->direction);
		else
			mVelocity=Vector(0,0);
	}

	if(relPosition.y < 400)
	{
		if(sf::Keyboard::isKeyPressed(mTeam->keys.right))
		{
			move(Vector(0,timeSinceLastFrame*400),TS_LOCAL);
			//rotate(-timeSinceLastFrame*360);
		}
	}

	if(relPosition.y>-400)
	{
		if(sf::Keyboard::isKeyPressed(mTeam->keys.left))
		{
			move(Vector(0,-timeSinceLastFrame*400),TS_LOCAL);
			//rotate(timeSinceLastFrame*360);
		}
	}

	if(sf::Keyboard::isKeyPressed(mTeam->keys.primary))
	{
		mPrimaryWeapon->tryFiring(timeSinceLastFrame);
	}
	if(mSecondaryWeapon!= nullptr && sf::Keyboard::isKeyPressed(mTeam->keys.secondary))
	{
		mSecondaryWeapon->tryFiring(timeSinceLastFrame);
	}

	//
	Vector vel = getPosition()-startPosition;
	//Some pretty particles :)
	mWorld->addActor(new Particle(sf::Color(mTeam->color),getPosition() - getDirectionVector()*32 + getDirectionVector().directOrthogonal()*10,-getDirectionVector()*mMaxSpeed));
	mWorld->addActor(new Particle(sf::Color(mTeam->color),getPosition() - getDirectionVector()*32 - getDirectionVector().directOrthogonal()*10,-getDirectionVector()*mMaxSpeed));

	mLifeBar.setPosition(getPosition()-getDirectionVector()*42);
	Actor::update(timeSinceLastFrame);
	return true;
}

void Ship::setPrimaryWeapon(BasicWeapon * weapon)
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
	{
		Bullet * blt = static_cast<Bullet*>(actor);
		if(blt->getTeam()!=mTeam)
		{
			takeDamage(1);
		}
	}
	else if(actor->getType()=="Ship")
		cout<<"I'm not a bullet"<<endl;

}

bool Ship::takeDamage(const Real & damages)
{
	mLife-=Math::clamp(2.,0.,mLife);
	mLifeBar.setValue(mLife/mMaxLife);
	if(mLife==0)
		return false;
	return true;
}

const MeasureBar & Ship::getLifeBar() const
{
	return mLifeBar;
}

// class Particle

Particle::Particle(const sf::Color & color, const Vector & position, const Vector & velocity):Actor("Particle",position,nullptr,velocity,PARTICLE_LAYER,true),mTimeToLive(0.30)
{
	setTexture(TextureManager::getInstance().getTexture("Flare"));
	setTextureColor(color);

}

bool Particle::update(const Real & timeSinceLastFrame)
{
	mTimeToLive-=timeSinceLastFrame;
	if(mTimeToLive<0)
		return false;
	sf::Color col = getTextureColor();
	col.a = Math::clamp(255.*(mTimeToLive/0.3)+20*mTimeToLive*mTimeToLive,0.,255.);
	setTextureColor(col);
	setScale((mTimeToLive+0.2)/0.5);
	Actor::update(timeSinceLastFrame);
	return true;
}
void Ship::onScore(const unsigned int & points)
{
	if(mPrimaryWeapon != nullptr)
		mPrimaryWeapon->onScore(points);
}
