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
	mValidate=false;
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
			convex->setFillColor(sf::Color::Transparent);
			convex->setOutlineColor(sf::Color::Red);
			convex->setOutlineThickness(1);
			//convex->setRotation(rotation);
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
	if(size()==0)
		radius = 0;
	relativeList.push_back(p);
	Real l = p.length();
	if(radius<l)
		radius=l;
}

Vector Body::ConvexHull::getLast()
{
	return relativeList.back();
}

Vector Body::ConvexHull::getB()
{
	return relativeList.front();
}

Vector Body::ConvexHull::getC()
{
	return relativeList.at(1);
}

int Body::ConvexHull::size() const
{
	return relativeList.size();
}

void Body::ConvexHull::remove(const Vector p)
{
	for (auto row=relativeList.begin(); row!=relativeList.end(); row++)
	{
		if (*row==p)
		{
			row=relativeList.erase(row);
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

void Body::prepare(Vector position,Real scale, Real angle, Math::AngleMode mode)
{
	if (!mValidate && mType==Body::CONVEX_HULL)
	{
		// on efface toutes les valeurs en coords absolues
		mHull.pointList.clear();
		
		//calculer la position absolue
		for (auto row:mHull.relativeList)
		{
			Vector vertex  = row.rotated(angle,Math::DEGREE)*scale+position;
			mHull.pointList.push_back(vertex);
		}
	}
	else if(!mValidate && mType==Body::CIRCLE)
	{
		mCircle.radius = mCircle.baseRadius*scale;
	}
	mValidate=true;
}
