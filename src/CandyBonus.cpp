#include "CandyBonus.h"
#include "CandyTextureManager.h"
using namespace Candy;
Bonus::Bonus(const Vector & position, const sf::Color & color):Actor("Bonus",position,new Body(Body::Circle{5})),mTimeToLive(4)
{
	setTexture(TextureManager::getInstance().getTexture("BonusM"));
	mSprite->setColor(color);
}

Bonus::~Bonus()
{

}

bool Bonus::update(const Real & t)
{
	mVelocity += t*Vector(Math::RealURNG::normalised()*100.-50.,Math::RealURNG::normalised()*100.-50);
	Actor::update(t);
	mTimeToLive-=t;

	if(mTimeToLive<0)
	{
		return false;
	}
	else if(mTimeToLive < 2)
	{
		sf::Color color = mSprite->getColor();
		color.a=(1-(int)(mTimeToLive*4)%2)*255;
		mSprite->setColor(color);
	}
	return true;
}
