#include "CandyAsteroid.h"
#include "CandyBody.h"
#include "CandyBullet.h"
#include "CandyShip.h"
#include "CandyTextureManager.h"
#include "CandyBasicWeapon.h"
#include "CandyRocketLauncher.h"
#include <iostream>
using namespace Candy;

Asteroid::Asteroid(World * world,const Vector & position,const Vector & velocity):
	Actor("Asteroid",position,new Body(Body::Circle({30})),velocity,BULLET_LAYER),mHit(false),mWorld(world),mAngularVelocity((Math::RealURNG::normalised()-0.5)*2.*Math::PI)
{
	Real rand = Math::RealURNG::normalised();
	if(rand<2./100.)
	{
		mBonus=Bonus::Life;
		setTexture(TextureManager::getInstance().getTexture("AsteroidLife"));
	}
	else if(rand<50./100)
	{
		mBonus=Bonus::Rocket;
		setTexture(TextureManager::getInstance().getTexture("AsteroidRocket"));
	}
	else
	{
		mBonus=Bonus::None;
		setTexture(TextureManager::getInstance().getTexture("AsteroidDefault"));

	}
}

Asteroid::~Asteroid()
{
}

bool Asteroid::update(const Real & timeSinceLastFrame)
{
	if(mHit || getPosition().x<-60 || getPosition().x > 860 || getPosition().y<-50 || getPosition().y > 650)
		return false;
	else
	{
		rotate(mAngularVelocity*timeSinceLastFrame,Math::RADIAN);
		Actor::update(timeSinceLastFrame);
		
	}return true;
}

void Asteroid::onCollision(Actor * actor)
{
	if(actor->getType()=="Bullet" || actor->getType()=="Ship")
	{
		if(actor->getType()=="Bullet")
		{
			Bullet * b = static_cast<Bullet*>(actor);
			switch(mBonus)
			{
				case Bonus::Life:
					b->getTeam()->getShip()->addLife(100);
					break;
				case Bonus::Rocket:
					b->getTeam()->getShip()->setSecondaryWeapon(new RocketLauncher(b->getTeam()->getShip()));
				case Bonus::None:
				default:
					break;
			}
		}

		mHit=true;
		setGhost(true);
	}
}
