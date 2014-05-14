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

Vector Body::ConvexHull::getFarthestPoint(Vector d)
{
	Vector result=pointList[0];
	Real farthestDistance=dot(pointList[0],d);
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

void Body::ConvexHull::delFirst()
{
	pointList.erase(pointList.begin());
}
