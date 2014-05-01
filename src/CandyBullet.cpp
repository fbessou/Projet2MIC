#include "CandyTextureManager.h"
#include "CandyBullet.h"
#include <iostream>
using namespace Candy;
Bullet::Bullet(const Vector & position, const Vector & velocity):Actor("Bullet", position,new Body(Body::Circle{5}),velocity),mTimeToLive(3)
{
	setTexture(TextureManager::getInstance().getTexture("Bullet"));
}
Bullet::~Bullet()
{
	std::cout<<"Bullet destroyed"<<std::endl;
}

bool Bullet::update( const Real & t)
{

	Actor::update(t);
	mTimeToLive-=t;
	if(mTimeToLive<0)
		return false;
	return true;

}