#include "CandyActor.h"
#include <SFML/Window.hpp>
#include <iostream>
using namespace Candy;

Actor::Actor(const string type, const Vector & position,Body * body, const Vector & velocity,const bool & ghost,const bool & visible):
	mType(type),
	mPosition(position),
	mVelocity(velocity),
	mBody(body),
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
	sf::FloatRect rect = sprite->getLocalBounds();
	sf::Vector2f center((rect.width-rect.left)/2,(rect.height-rect.top)/2);
	sprite->setOrigin(center);

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
void Actor::move(const Vector & translation, const TransformSpace & ts)
{
		
	sf::Vector2f tmp = mSprite->getPosition();
	switch(ts)
	{
		case TS_WORLD:
			mSprite->move(translation.x,translation.y);
			break;
		case TS_LOCAL:
			sf::Transform localTransform = sf::Transform::Identity;
			localTransform.rotate(mSprite->getRotation());
			mSprite->move(localTransform.transformPoint(translation.x,translation.y));
	}
	tmp = mSprite->getPosition();
	mPosition= {tmp.x,tmp.y};
}

void Actor::rotate(const Real & angle)
{
	mSprite->rotate(angle);
}

void Actor::onCollision(Actor* actor)
{

}


