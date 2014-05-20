#include <iostream>
#include "CandyWeapon.h"

using namespace Candy;

Weapon::Weapon(Ship * owner, const unsigned & ammo, const Real & rate):
	mOwner(owner),
	mAmmoStock(ammo),
	mFireRate(rate),
	mTimeBeforeNextShoot(0){}

Weapon::~Weapon()
{

}

bool Weapon::tryFiring(const Real & t)
{
	mTimeBeforeNextShoot -=t;
	if(mTimeBeforeNextShoot<=0 && mAmmoStock >0)
	{
		mAmmoStock -= fire();
		mTimeBeforeNextShoot=1./mFireRate;
		return true;
	}

	return false;
}

const Real & Weapon::getFireRate() const
{
	return mFireRate;
}
