#include "CandyAsteroid.h"
#include "CandyBody.h"
#include "CandyTextureManager.h"
#include <iostream>
using namespace Candy;

Asteroid::Asteroid(World * world,const Vector & position,const Vector & velocity):
	Actor("Asteroid",position,new Body(Body::Circle({30})),velocity,BULLET_LAYER),mHitBullet(false),mWorld(world)
{
	setTexture(TextureManager::getInstance().getTexture("Asteroid"));
}

Asteroid::~Asteroid()
{
}

bool Asteroid::update(const Real & timeSinceLastFrame)
{
	if(mHitBullet)
		return false;
	else
		Actor::update(timeSinceLastFrame);
	return true;
}

void Asteroid::onCollision(Actor * actor)
{
	if(actor->getType()=="Bullet")
	{
		mHitBullet=true;
	}
}
