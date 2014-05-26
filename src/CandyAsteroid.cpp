#include "CandyAsteroid.h"
#include "CandyBody.h"
#include "CandyTextureManager.h"
#include <iostream>
using namespace Candy;

Asteroid::Asteroid(World * world,const Vector & position,const Vector & velocity):
	Actor("Asteroid",position,new Body(Body::Circle({30})),velocity,BULLET_LAYER),mHitBullet(false),mWorld(world),mAngularVelocity((Math::RealURNG::normalised()-0.5)*2.*Math::PI)
{
	setTexture(TextureManager::getInstance().getTexture("Asteroid"));
}

Asteroid::~Asteroid()
{
	std::cout<<"Test"<<std::endl;
}

bool Asteroid::update(const Real & timeSinceLastFrame)
{
	if(mHitBullet || getPosition().x<-60 || getPosition().x > 860 || getPosition().y<-50 || getPosition().y > 650)
		return false;
	else
	{
		rotate(mAngularVelocity*timeSinceLastFrame,Math::RADIAN);
		Actor::update(timeSinceLastFrame);
		
	}return true;
}

void Asteroid::onCollision(Actor * actor)
{
	if(actor->getType()=="Bullet")
	{
		mHitBullet=true;
	}
}
