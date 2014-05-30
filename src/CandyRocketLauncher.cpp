#include "CandyRocketLauncher.h"
#include "CandyBody.h"
#include "CandyTextureManager.h"
#include "CandyTeam.h"
#include "CandyWorld.h"

using namespace Candy;
Rocket::Rocket(Team * team, const Vector & position, const Vector & velocity,const Actor * target):
   	Actor("Rocket",position,new Body(Body::Circle{12}),
			velocity,BULLET_LAYER),
	mTarget(target),
	mTimeToLive(7),mDestroyed(false),mTeam(team),
	mMaxScale(0.8),
	mDamagesInflicted(30),
	mAnimate(true)
{
	setTexture(TextureManager::getInstance().getTexture("Rocket"));
	setTextureColor(mTeam->color);
	setDirectionVector(velocity);
	setScale(mMaxScale);
}

bool Rocket::update(const Real & timeSinceLastFrame)
{
	mTimeToLive -= timeSinceLastFrame;
	//start to decrease the scale of the bullet
	if(mTimeToLive < 0.3 && mAnimate)
	{
		sf::Color col = getTextureColor();
		col.a = 255*(mTimeToLive/0.3);
		setTextureColor(col);
		setScale(mMaxScale*mTimeToLive/0.3);
	}
	if(mDestroyed == true || mTimeToLive<0)
		return false;
	if(mTarget!=nullptr)
	{	
		mVelocity = mVelocity - 1.5*timeSinceLastFrame*mVelocity;
		mVelocity += 500*(mTarget->getPosition() - getPosition()).normalisedCopy()*timeSinceLastFrame;
		setDirectionVector(mVelocity);
	}
	Actor::update(timeSinceLastFrame);
	return true;
}
Team * Rocket::getTeam()
{
	return mTeam;
}
void Rocket::onCollision(Actor * actor)
{
	//Le missile est detruit a l'impact avec un vaisseau.
	if(actor->getType() == "Ship" )
	{
		if(static_cast<Ship*>(actor)->getTeam() != mTeam)
		{
			mTeam->score(20);
			mDestroyed = true;
		}
	}

}

RocketLauncher::RocketLauncher(Ship * owner):Weapon(owner,2,3)
{

}

RocketLauncher::~RocketLauncher()
{

}

unsigned int RocketLauncher::fire()
{
	mOwner->getWorld()->addActor(new Rocket(mOwner->getTeam(),mOwner->getPosition()+mOwner->getDirectionVector()*30,mOwner->getAimDirection()*500,mOwner->getTeam()->getOpponent()->getShip()));
	return 1;
}


