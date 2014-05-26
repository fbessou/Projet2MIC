#include <iostream>
#include "CandyBasicWeapon.h"
#include "CandyBullet.h"
#include "CandyWorld.h"
#include "CandyTextureManager.h"
#define MAX_WEAPON_LEVEL 5
using namespace Candy;

BasicWeapon::BasicWeapon(Ship * owner):Weapon(owner,1,2),
	mLevel(1),
	mStep(0),
	mNextLevelScore(100),
	mCurrentLevelScore(0)

{
}

BasicWeapon::~BasicWeapon()
{}

unsigned int BasicWeapon::fire()
{
	Vector dir = mOwner->getDirectionVector();
	Real shootSpeed = Math::clamp(mLevel*50 + mStep*mLevel*150+100,0,450);
	if(mLevel==1)
	{
		mOwner->getWorld()->addActor(new Bullet(mOwner->getTeam(),mOwner->getPosition()+dir*42,dir*shootSpeed*1.10));
	}
	else if(mLevel==2)
	{
		mOwner->getWorld()->addActor(new Bullet(mOwner->getTeam(),mOwner->getPosition()+dir*30+dir.directOrthogonal()*7,dir*shootSpeed));
		mOwner->getWorld()->addActor(new Bullet(mOwner->getTeam(),mOwner->getPosition()+dir*30-dir.directOrthogonal()*7,dir*shootSpeed));
	}
	else if(mLevel>=3)
	{
		Real shootSpeed = Math::clamp(mLevel*150,0,400);
		mOwner->getWorld()->addActor(new Bullet(mOwner->getTeam(),mOwner->getPosition()+dir*42,dir*shootSpeed*1.10));
		mOwner->getWorld()->addActor(new Bullet(mOwner->getTeam(),mOwner->getPosition()+dir*30+dir.directOrthogonal()*7,dir.rotated(10,Math::DEGREE)*shootSpeed));
		mOwner->getWorld()->addActor(new Bullet(mOwner->getTeam(),mOwner->getPosition()+dir*30-dir.directOrthogonal()*7,dir.rotated(-10,Math::DEGREE)*shootSpeed));
	}
	return 0;
}

void BasicWeapon::onScore(const Real & score)
{
	if(score>=mNextLevelScore && mLevel <= MAX_WEAPON_LEVEL)
		improve();
	mStep=(score-mCurrentLevelScore)/mNextLevelScore;
}
void BasicWeapon::improve()
{
	mCurrentLevelScore=mNextLevelScore;
	mNextLevelScore=2.25*mCurrentLevelScore;
	mLevel++;
	if(mLevel<4)
		mFireRate = mFireRate*1.5;
	else
		mFireRate = 3;
	std::cout<<mNextLevelScore<<" : "<<mLevel<<std::endl;
}


