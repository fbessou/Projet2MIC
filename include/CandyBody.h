#ifndef _CANDY_BODY_H_
#define _CANDY_BODY_H_
#include "CandyCommon.h"

#include "CandyMath.h"
#include <SFML/Graphics.hpp>
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

				// access to the farthest point in a given direction
				Vector getFarthestPoint(Vector d);

				// add point to the end of the list
				void addPoint(Vector p);
				// get the lastly added point
				Vector getLast();
				
				//delete the firstly added point
				void delFirst();
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
			Body( const Circle & circle, const Vector & center = Vector(0,0));
			Body( const ConvexHull & hull, const Vector & center = Vector(0,0));

			~Body();
			sf::Drawable * getAsDrawable(const Vector &, const Real&) const;
			void setCenter(const Vector & center);
			const Vector & getCenter() const;

			const Type & getType() const;
			// void setType(Type);

			// acces direct aux formes
			const Rectangle & getRectangle() const ;
			const Circle & getCircle() const;
			const ConvexHull & getConvexHull() const;
	};
};

#endif 
