#ifndef _CANDY_BODY_H_
#define _CANDY_BODY_H_
#include "CandyCommon.h"

#include "CandyMath.h"
#include <vector>
namespace Candy
{
	class Body
	{	
		public:
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
				std::vector<Vector> pointList;
			};

			enum Type
			{
				RECTANGLE,
				CIRCLE,
				CONVEX_HULL
			};
		protected:
			union
			{
				Rectangle mRectangle;
				Circle mCircle;
				ConvexHull mHull;
			};

			Vector mCenter;
			Type mType;
		public:
			Body( const Rectangle & rectangle , const Vector & center =Vector(0,0));
			Body( const Circle & circle, const Vector &);
			Body( const ConvexHull & hull, const Vector &);

			~Body();

			void setCenter(const Vector & center);
			const Vector & getCenter() const;

			const Type & getType() const;
			// void setType(Type);

			// acces direct aux formes
			Rectangle & getRectangle();
			Circle & getCircle();
			ConvexHull & getConvexHull();





	};
};
#endif
