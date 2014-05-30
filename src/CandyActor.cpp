#include "CandyActor.h"
#include <SFML/Window.hpp>
#include <iostream>
#include "CandyBody.h"
using namespace Candy;

Actor::Actor(const std::string type, const Vector & position,Body * body, const Vector & velocity, const unsigned int & layer, const bool & ghost,const bool & visible):
	mType(type),
	mSprite(new sf::Sprite()),
	mVelocity(velocity),
	mBody(body),
	mGhost(ghost),
	mVisible(visible),
	mLayer(layer)
{
	setPosition(position);
}

Actor::~Actor()
{
}
void Actor::_onOwnerChanged(World * owner)
{
	mWorld=owner;
}

bool Actor::update(const Real &  step)
{
	move(getVelocity()*step);
	return true;
}

void Actor::draw(sf::RenderTarget & target)
{
	target.draw(*getSprite(),sf::RenderStates::Default);
	if(!isGhost())
	{
		sf::Drawable * hullShape = getBody()->getAsDrawable(mPosition,getRotation());
		target.draw(*hullShape);
		delete hullShape;
	}
}

const Body * Actor::getBody() const {
	return mBody;
}

std::string Actor::getType() const
{
	return mType;
}

void Actor::setTexture(const sf::Texture & texture)
{
	mSprite->setTexture(texture);
	sf::FloatRect rect = mSprite->getLocalBounds();
	sf::Vector2f center((rect.width-rect.left)/2,(rect.height-rect.top)/2);
	mSprite->setOrigin(center);
}

void Actor::setTextureColor(const sf::Color & color )
{
	mSprite->setColor(color);
}
const sf::Color & Actor::getTextureColor() const
{
	return mSprite->getColor();
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
	if (!isGhost())
	{
		mBody->invalidate();
	}

}

Real Actor::getScale() const
{
	return mSprite->getScale().x;
}

void Actor::setScale(const Real & scale)
{
	mSprite->setScale(Vector(scale,scale));
	if (!isGhost())
	{
		mBody->invalidate();
	}
}

const Vector& Actor::getVelocity() const
{
	return mVelocity;
}

void Actor::setVelocity(const Vector& velocity)
{
	mVelocity = velocity;
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

	if (!isGhost())
	{
		mBody->invalidate();
	}
}

void Actor::rotate(const Real & angle,const Math::AngleMode & mode)
{

	mSprite->rotate(mode == Math::DEGREE ? angle : angle *180./Math::PI);
	if(!isGhost())
		mBody->invalidate();
}

Real Actor::getRotation(const Math::AngleMode & mode)
{
	return (mode == Math::DEGREE ? mSprite->getRotation(): mSprite->getRotation()*Math::PI/180);
}

void Actor::setRotation(const Real & angle, const Math::AngleMode & mode)
{
	mSprite->setRotation(mode==Math::DEGREE?angle:angle*180/Math::PI);
	if(!isGhost())
		mBody->invalidate();
}

Vector Actor::getDirectionVector()
{
	Real rot = getRotation(Math::RADIAN);
	Vector v(cos(rot),sin(rot));
	return v;
}

void Actor::setDirectionVector(const Vector & direction)
{
	setRotation(Math::atan2(direction.y,direction.x),Math::RADIAN);
}

void Actor::lookAt(const Vector & position)
{
	setDirectionVector(getPosition()-position);
}


void Actor::onCollision(Actor* actor)
{
	std::cout<<"collision"<<std::endl;

}

void Actor::prepare()
{
	mBody->prepare(getPosition(),getScale(),getRotation());
}

bool ActorComparator::operator()(const Actor * a1, const Actor * a2)
{
	bool la1_inf_la2 = a1->mLayer < a2->mLayer;
	bool la1_eq_la2 = a1->mLayer == a2->mLayer;
	bool a1_inf_a2 = la1_eq_la2 ? a1<a2 : la1_inf_la2;
	return a1_inf_a2;
}
