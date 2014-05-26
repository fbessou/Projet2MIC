#include "CandyTextureManager.h"
#include "CandyBody.h"
#include "CandyBullet.h"
#include <iostream>
using namespace Candy;
Bullet::Bullet(Team * team, const Vector & position, const Vector & velocity):Actor("Bullet", position,new Body(Body::Circle{5}),velocity,BULLET_LAYER),mTimeToLive(5),mHitObstacle(false),mTeam(team)
{
	setTexture(TextureManager::getInstance().getTexture("Bullet"));
	setTextureColor(mTeam->color);
}

Bullet::~Bullet()
{
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
	if(actor->getType()=="Ship")
	{
		mTeam->score(10);
		mHitObstacle = true;
	}
}
