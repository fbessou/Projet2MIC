#include "CandyBasicWeapon.h"
#include "CandyBullet.h"

using namespace Candy;

BasicWeapon::BasicWeapon(Ship * owner):Weapon(owner,1,5)
{

}

BasicWeapon::~BasicWeapon()
{}

unsigned int BasicWeapon::fire()
{
	Vector dir = mOwner->getDirectionVector();
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+dir*42,mOwner->getDirectionVector()*550));
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+dir*42+Vector::UNIT_X*2,mOwner->getDirectionVector().rotated(-Math::PI/50,Math::DEGREE)*500));
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+dir*42-Vector::UNIT_X*2,mOwner->getDirectionVector().rotated(Math::PI/50,Math::DEGREE)*500));
	return 0;
}
