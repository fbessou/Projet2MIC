#include "CandyBody.h"
using namespace Candy;

Body::Body(const Rectangle & rect, const Vector & center ):mRectangle(rect),mCenter(0,5)
{
	mType = RECTANGLE;
	
}

Body::Body(const Circle & circle,const Vector & center ):mCenter(center),mCircle(circle)
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

Type Body::getType() const
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
