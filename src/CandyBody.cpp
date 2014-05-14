#include "CandyBody.h"

using namespace Candy;

Body::Body(const Rectangle & rect, const Vector & center ):mRectangle(rect),mCenter(center)
{
	mType = RECTANGLE;
	
}

Body::Body(const Circle & circle,const Vector & center ):mCircle(circle),mCenter(center)
{
	mType = CIRCLE;
	mCircle = circle;
}

Body::Body(const ConvexHull & hull, const Vector & center) : mCenter(center)
{
	mType = CONVEX_HULL;
	new (&mHull) ConvexHull(mHull);
}

Body::~Body(){

}

const Body::Type & Body::getType() const
{
	return mType;
}

void Body::setCenter( const Vector & center)
{
	mCenter = center;
}

const Vector & Body::getCenter() const
{
	return mCenter;
}

const Body::Circle & Body::getCircle() const
{
	return mCircle;
}

const Body::Rectangle & Body::getRectangle() const
{
	return mRectangle;
}

const Body::ConvexHull & Body::getConvexHull() const
{
	return mHull;
}

sf::Drawable * Body::getAsDrawable(const Vector & position, const Real & rotation) const 
{
	sf::Drawable * dr = nullptr;
	switch(mType)
	{
		sf::RectangleShape * rect;
		sf::CircleShape * circle;
		sf::FloatRect * bounds;
		case Body::RECTANGLE :
			rect = new sf::RectangleShape();
			rect->setPosition(position);
			rect->setRotation(rotation);
			bounds=new sf::FloatRect(rect->getLocalBounds());
			rect->setOrigin((bounds->width-bounds->left)/2,(bounds->height-bounds->top)/2);
			rect->setFillColor(sf::Color::Transparent);
			rect->setOutlineColor(sf::Color::Red);
			rect->setOutlineThickness(1);
			dr=rect;
			break;
		case Body::CIRCLE:
			circle = new sf::CircleShape(mCircle.radius,16);
			circle->setPosition(position);
			bounds=new sf::FloatRect(circle->getLocalBounds());
			circle->setOrigin((bounds->width-bounds->left)/2,(bounds->height-bounds->top)/2);
			circle->setFillColor(sf::Color::Transparent);
			circle->setOutlineColor(sf::Color::Red);
			circle->setOutlineThickness(1);
			dr=circle;
			break;
		 default:
			break;
	}
	return dr;
}
