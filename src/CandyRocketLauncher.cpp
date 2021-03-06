#include "CandyRocketLauncher.h"
#include "CandyBody.h"
#include "CandyTextureManager.h"
#include "CandyTeam.h"
#include "CandyWorld.h"

using namespace Candy;

Body * createRocketBody()
{
	Body::ConvexHull hull;
	hull.addPoint(Vector(30,0));
	hull.addPoint(Vector(25,5));
	hull.addPoint(Vector(0,10));
	hull.addPoint(Vector(-28,10));
	hull.addPoint(Vector(-30,0));
	hull.addPoint(Vector(-28,-10));
	hull.addPoint(Vector(0,-10));
	hull.addPoint(Vector(25,-5));
	return new Body(hull); 
}
Rocket::Rocket(Team * team, const Vector & position, const Vector & velocity,const Actor * target):
   	Actor("Rocket",position,createRocketBody(),
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

RocketLauncher::RocketLauncher(Ship * owner):Weapon(owner,2,3),
	mRocketSprite(TextureManager::getInstance().getTexture("Rocket"))
{
	sf::FloatRect rect = mRocketSprite.getLocalBounds();
	sf::Vector2f center((rect.width-rect.left)/2,(rect.height-rect.top)/2);
	mRocketSprite.setScale(0.7,0.7);
	mRocketSprite.setOrigin(center);
	mRocketSprite.setColor(mOwner->getTeam()->color);

}

RocketLauncher::~RocketLauncher()
{

}
void RocketLauncher::draw(sf::RenderTarget & target)
{
	mRocketSprite.setRotation(mOwner->getRotation());
	Vector pos = -5*mOwner->getDirectionVector();
	if(mAmmoStock >= 1)
	{
		mRocketSprite.setPosition(mOwner->getPosition()+pos+20*mOwner->getDirectionVector().directOrthogonal());
		target.draw(mRocketSprite);
	}
	if(mAmmoStock == 2)
	{
		mRocketSprite.setPosition(mOwner->getPosition()+pos-20*mOwner->getDirectionVector().directOrthogonal());
		target.draw(mRocketSprite);
	}
}

unsigned int RocketLauncher::fire()
{
	mOwner->getWorld()->addActor(new Rocket(mOwner->getTeam(),mOwner->getPosition()+mOwner->getDirectionVector()*30,mOwner->getAimDirection()*500,mOwner->getTeam()->getOpponent()->getShip()));
	return 1;
}


