#include "CandyActor.h"

using namespace Candy;

Actor::Actor(const string type, const Vector & position, const Vector & velocity,const bool & ghost,const bool & visible):
	mType(type),
	mPosition(position),
	mVelocity(velocity),
	mGhost(ghost),
	mVisible(visible)

{
	
}

void Actor::update(unsigned int step)
{
	setPosition(getPosition()+getVelocity()*step);
}

void Actor::draw()
{
	if(isVisible())
		return;
		//mShape->draw();//TODO implement
}

const Body * Actor::getBody() const
{
	return mBody;
}

string Actor::getType() const
{
	return mType;
}

const bool& Actor::isVisible() const
{
	return mVisible;
}

void Actor::setVisible(const bool & visible = true)
{
	mVisible = visible;
}

const bool & Actor::isGhost() const
{
	return mGhost;
}

void Actor::setGhost(const bool & ghost = true)
{
	mGhost = ghost;
}

const Vector& Actor::getPosition() const
{
	return mPosition;
}

void Actor::setPosition(const Vector& position)
{
	mPosition = position;
	//mShape.position = position;
}

const Vector& Actor::getVelocity() const
{
	return mVelocity;
}

void Actor::setVelocity(const Vector& velocity)
{
	mVelocity = velocity;
	//mShape.velocity = velocity;
}

void Actor::onCollision(Actor* actor)
{

}
