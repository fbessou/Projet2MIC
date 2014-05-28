#include "CandyRocketLauncher.h"
#include "CandyBody.h"
#include "CandyTextureManager.h"
#include "CandyTeam.h"
#include "CandyWorld.h"

using namespace Candy;
Rocket::Rocket(Team * team, const Vector & position, const Vector & velocity,const Actor * target): Actor("Rocket",position,new Body(Body::Circle{5}),velocity,BULLET_LAYER),mTarget(target),mTimeToLive(7),mDestroyed(false),mTeam(team)
{
	setTexture(TextureManager::getInstance().getTexture("Bullet"));
	setTextureColor(mTeam->color);
	setDirectionVector(velocity);
	setScale(3);
}

bool Rocket::update(const Real & timeSinceLastFrame)
{

	mTimeToLive -= timeSinceLastFrame;
	if(mTimeToLive < 1)
	{
		sf::Color col = getTextureColor();
		col.a = 255*(mTimeToLive);
		setTextureColor(col);
		setScale(3*mTimeToLive);
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
			mDestroyed = true;
	}

}

RocketLauncher::RocketLauncher(Ship * owner):Weapon(owner,5,3)
{

}

RocketLauncher::~RocketLauncher()
{

}

unsigned int RocketLauncher::fire()
{
	mOwner->getWorld()->addActor(new Rocket(mOwner->getTeam(),mOwner->getPosition(),mOwner->getAimDirection()*500,mOwner->getTeam()->getOpponent()->getShip()));
	return 1;
}


