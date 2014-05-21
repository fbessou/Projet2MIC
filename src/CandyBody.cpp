#include "CandyBody.h"
#include <iostream>

using namespace Candy;
using namespace std;

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
	new (&mHull) ConvexHull(hull);
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
		sf::ConvexShape * convex;
		int index;
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
		case Body::CONVEX_HULL:
			index=0;
			convex = new sf::ConvexShape(mHull.size());
			for (auto point:mHull.pointList)
			{
				convex->setPoint(index,point);
				index++;
			}
			convex->setPosition(position);
			convex->setFillColor(sf::Color::Transparent);
			convex->setOutlineColor(sf::Color::Red);
			convex->setOutlineThickness(1);
			dr=convex;
			break;
		 default:
			break;
	}
	return dr;
}

Vector Body::ConvexHull::getFarthestPoint(Vector d) const
{
	Vector result;
	if(!(pointList.empty()))
	{
		result=(*(pointList.begin()));
		Real farthestDistance=dot(result,d);
		Real tmp;
		for (auto row:pointList)
		{
			tmp=dot(row,d);
			if (tmp>farthestDistance)
			{
				farthestDistance=tmp;
				result=row;
			}
		}
	}
	return result;
}

void Body::ConvexHull::addPoint(Vector p)
{
	pointList.push_back(p);
}

Vector Body::ConvexHull::getLast()
{
	return pointList.back();
}

Vector Body::ConvexHull::getB()
{
	return pointList.front();
}

Vector Body::ConvexHull::getC()
{
	return pointList.at(1);
}

int Body::ConvexHull::size() const
{
	return pointList.size();
}

void Body::ConvexHull::remove(const Vector p)
{
	for (auto row=pointList.begin(); row!=pointList.end(); row++)
	{
		if (*row==p)
		{
			row=pointList.erase(row);
		}
	}
}

const bool & Body::isValidate() const
{
	return mValidate;
}

void Body::invalidate()
{
	mValidate=false;
}

void Body::prepare(Vector position, Real angle, Math::AngleMode mode)
{
	if (mValidate)
	{
	}else{

		// on efface toutes les valeurs absolues
		mHull.pointList.clear();

		// retourner tous les vecteurs

		//calculer la position absolue
		for (auto row:mHull.relativeList)
		{
			mHull.pointList.push_back(row.rotated(angle)+position);
		}

		mValidate=true;
	}
}
