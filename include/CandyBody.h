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
				std::vector<Vector> relativeList;
				// access to the farthest point in a given direction
				Vector getFarthestPoint(Vector d) const;

				// add point to the end of the list
				void addPoint(Vector p);
				// get the lastly added point
				// to use for collision
				Vector getLast();
				//get the first one on the list
				Vector getB();
				//get the second one
				Vector getC();
				int size() const;

				Real radius;
				//delete the firstly added point
				void remove(const Vector p);
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

			// regarde si les données du hull sont valides
			bool mValidate;
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

			const bool & isValidate() const;
			void prepare(Vector position,Real angle,Math::AngleMode mode=Math::DEGREE);
			void invalidate();
	};
};

#endif 
