#include <iostream>
#include "CandyBasicWeapon.h"
#include "CandyBullet.h"
#include "CandyWorld.h"
#include "CandyTextureManager.h"
#define MAX_WEAPON_LEVEL 5
using namespace Candy;

BasicWeapon::BasicWeapon(Ship * owner):Weapon(owner,1,3),
	mLevel(1),
	mStep(0),
	mNextLevelScore(500),
	mCurrentLevelScore(0),
	mShotSpeed(200)

{
}

BasicWeapon::~BasicWeapon()
{

}

unsigned int BasicWeapon::fire()
{
	Team * team = mOwner->getTeam();
	Vector shipDir = mOwner->getDirectionVector();
	Vector aimDir = mOwner->getAimDirection();
	Vector left = shipDir.directOrthogonal();
	Vector source = mOwner->getPosition()+shipDir*30;
	if(mLevel==1)
	{
		mOwner->getWorld()->addActor(new Bullet( team, source, aimDir*mShotSpeed*1.10 ) );
	}
	else if(mLevel==2)
	{
		mShotSpeed = (450 - 300 )*mStep + 450;

		mOwner->getWorld()->addActor(new Bullet(team,source+left*7,aimDir*mShotSpeed));
		mOwner->getWorld()->addActor(new Bullet(team,source-left*7,aimDir*mShotSpeed));

	}
	else if(mLevel==3)
	{
		mOwner->getWorld()->addActor(new Bullet( team, source, aimDir*mShotSpeed*1.10 ) );
		mOwner->getWorld()->addActor(new Bullet(team,source+left*7,aimDir.rotated(10,Math::DEGREE)*mShotSpeed));
		mOwner->getWorld()->addActor(new Bullet(team,source-left*7,aimDir.rotated(-10,Math::DEGREE)*mShotSpeed));

	}
	else if(mLevel>=4)
	{
		mOwner->getWorld()->addActor(new Bullet(team,source+left*7,aimDir*mShotSpeed));
		mOwner->getWorld()->addActor(new Bullet(team,source-left*7,aimDir*mShotSpeed));
		mOwner->getWorld()->addActor(new Bullet(team,source+left*7,aimDir.rotated(10,Math::DEGREE)*mShotSpeed));
		mOwner->getWorld()->addActor(new Bullet(team,source-left*7,aimDir.rotated(-10,Math::DEGREE)*mShotSpeed));
	}
	return 0;
}


void BasicWeapon::onScore(const Real & score)
{
	changeFireRate();
	if(score>=mNextLevelScore && mLevel <= MAX_WEAPON_LEVEL)
		improve();
	mStep=(score-mCurrentLevelScore)/mNextLevelScore;
}

void BasicWeapon::changeFireRate()
{
	if(mLevel == 1)
	{
		mShotSpeed = (300 - 200 )*mStep + 200;
		mFireRate =  (4. - 3.)*mStep + 3.;

	}
	else if(mLevel == 2)
	{
		mShotSpeed = (450 - 300 )*mStep + 300;
		mFireRate =  (5. - 3.)*mStep + 3.;
	}
	else if(mLevel == 3)
	{
		mShotSpeed = (450 - 350 )*mStep + 350;
		mFireRate =  (4. - 2.)*mStep + 2.;
	}
	else
	{
		mShotSpeed = (500 - 400 )*mStep + 400;
		mFireRate =  (3. - 2.)*mStep + 2.;
	}
}

void BasicWeapon::improve()
{
	mCurrentLevelScore=mNextLevelScore;
	mNextLevelScore=2.25*mCurrentLevelScore;
	mLevel++;
	std::cout<<mNextLevelScore<<" : "<<mLevel<<std::endl;
}


