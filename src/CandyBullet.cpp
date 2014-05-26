#include "CandyTextureManager.h"
#include "CandyBody.h"
#include "CandyBullet.h"
#include <iostream>
#include "CandyShip.h"
using namespace Candy;
Bullet::Bullet(Team * team, const Vector & position, const Vector & velocity):Actor("Bullet", position,new Body(Body::Circle{5}),velocity,BULLET_LAYER),mTimeToLive(5),mHitObstacle(false),mTeam(team)
{
	setTexture(TextureManager::getInstance().getTexture("Bullet"));
	setTextureColor(mTeam->color);
}

Bullet::~Bullet()
{
}

Team * Bullet::getTeam()
{
	return mTeam;
}
bool Bullet::update( const Real & t)
{

	Actor::update(t);
	mTimeToLive-=t;
	if(mTimeToLive<0 || mHitObstacle)
		return false;
	return true;

}

void Bullet::onCollision(Actor * actor)
{
	std::string type = actor->getType();
	if(type=="Ship" )
	{
		Ship * ship = static_cast<Ship*>(actor);
		if(ship->getTeam() != mTeam)
		{
			mTeam->score(5);
			mHitObstacle = true;
		}
	}
	else if(type=="Asteroid")
	{
		mTeam->score(10);
			mHitObstacle = true;
	}
}
