#ifndef _CANDY_MATH_H_
#define _CANDY_MATH_H_

#include "CandyCommon.h"

#include <ostream>

namespace Candy
{
	class Vector
	{
		public:
			Real x,y;
		public:
			Vector(const Real & ,const Real &);
			~Vector();

			bool isNormalized() const;
			void normalize(); 
			Vector normalizedCopy() const;

			Real dotProduct(const Vector & ) const;
			Vector operator+(const Vector & ) const;
			Vector operator-(const Vector &) const;
			Vector operator*(const Real &) const;
			Vector operator/(const Real &) const;
			const Vector & operator=(const Vector &);
			const Vector & operator+=(const Vector &);
			const Vector & operator-=(const Vector &);
			const Vector & operator*=(const Real &);
			const Vector & operator/=(const Real &);
			//Real angleBetween(Vec)
			Real length() const; // return the magnitude of the vector
			Real squaredLength() const; // return the squared magnitude of the vector (much faster)
		public:
			static const Vector UNIT_X;
			static const Vector UNIT_Y;
	};

	std::ostream& operator<<(std::ostream& stream, const Vector& v);

	namespace Math
	{
		
	};

};
#endif

