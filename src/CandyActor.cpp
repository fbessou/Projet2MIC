#include "CandyActor.h"
#include <SFML/Window.hpp>
#include <iostream>
using namespace Candy;

Actor::Actor(const string type, const Vector & position, const Vector & velocity,const bool & ghost,const bool & visible):
	mType(type),
	mPosition(position),
	mVelocity(velocity),
	mGhost(ghost),
	mVisible(visible)

{
	
}

Actor::~Actor()
{
}

void Actor::update(const Real &  step)
{
	setPosition(getPosition()+getVelocity()*step);
}

void Actor::draw(sf::RenderTarget & target)
{
	target.draw(*getSprite(),sf::RenderStates::Default);
}

const Body * Actor::getBody() const
{
	return mBody;
}

string Actor::getType() const
{
	return mType;
}
void Actor::setSprite(sf::Sprite * sprite)
{
	mSprite = sprite;
	//sf::FloatRect * rect = mSprite.getLocalBounds();
	
	
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
	mSprite->setPosition(position.x,position.y);
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
