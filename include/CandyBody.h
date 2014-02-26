#ifndef _CANDY_BODY_H_
#define _CANDY_BODY_H_
#include "CandyCommon.h"

#include "CandyMath.h"

class Body
{	
	protected:
	void * mShape; //pointeur sur la structure appropriee
	Vector mCenter;

public:
	Body(Rectangle);
	Body(Circle);
	Body(ConvexHull);
	
	~Body();

	void setCenter(const Vector & center);
	void getCenter(const Vector & center) const;

	const Type & getType() const;
	void setType();

	// acces direct aux formes
	Rectangle & getRectangle();
	Circle & getCircle();
	ConvexHull & getConvexHull();
	
	//public types
	struct Rectangle
	{
		bool axisAligned;
		Real width;
		Real height;
	};

	struct Circle
	{
		Real radius;
	};

	struct ConvexHull
	{
		std::vector<Vector> hull;
	}

	enum Type
	{
		RECTANGLE,
		CIRCLE,
		CONVEX_HULL
	};

	
	

};
#endif
