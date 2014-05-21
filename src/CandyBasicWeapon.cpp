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
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+dir*42,mOwner->getDirectionVector()*500));
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+dir*42+Vector::UNIT_X*20,mOwner->getDirectionVector()*500));
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+dir*42-Vector::UNIT_X*20,mOwner->getDirectionVector()*500));
	return 0;
}
