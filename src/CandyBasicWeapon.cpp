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
	mOwner->getWorld()->addActor(new Bullet(mOwner->getPosition()+mOwner->getDirectionVector()*42,mOwner->getDirectionVector()*250));
	return 0;
}
