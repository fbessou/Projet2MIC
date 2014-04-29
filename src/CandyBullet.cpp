#include "CandyTextureManager.h"
#include "CandyBullet.h"
#include <iostream>
using namespace Candy;
Bullet::Bullet(const Vector & position, const Vector & velocity):Actor("Bullet", position,new Body(Body::Circle{5}),velocity)
{
	setTexture(TextureManager::getInstance().getTexture("Bullet"));
}
Bullet::~Bullet()
{
}
