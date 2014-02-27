#include "CandyBody.h"

using namespace Candy;

Body::Body(const Rectangle & rect)
{
	mType = RECTANGLE;
}

Body::Body(const Circle & circle)
{
	mType = CIRCLE;
}

Body::Body(const ConvexHull & hull)
{
	mType = ConvexHull;
}

Body::
