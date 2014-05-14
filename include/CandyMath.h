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

			bool isNormalised() const;
			void normalise(); 
			Vector normalisedCopy() const;

			Real dotProduct(const Vector & ) const;
			Vector operator+(const Vector & ) const;
			Vector operator-(const Vector &) const;
			Vector operator/(const Real &) const;
			const Vector & operator=(const Vector &);
			const Vector & operator+=(const Vector &);
			const Vector & operator-=(const Vector &);
			const Vector & operator*=(const Real &);
			const Vector & operator/=(const Real &);
			const Vector & operator-();
			bool operator==(const Vector &);
			bool operator<(const Vector &);
			//Real angleBetween(Vec)
			Real length() const; // return the magnitude of the vector
			Real squaredLength() const; // return the squared magnitude of the vector (much faster)
			operator std::string() const;

			//negate a Vector
			void negate();
		public:
			static const Vector UNIT_X;
			static const Vector UNIT_Y;
	};
	//pour la commutativité, on place les opérateur
	Vector operator*(const Real &,const Vector &);
	Vector operator*(const Vector & , const Real &);
	//produit scalaire entre deux vecteurs de dimension 2
	Real dot(const Vector &, const Vector &);

	std::ostream& operator<<(std::ostream& stream, const Vector& v);

	namespace Math
	{
	  Real min(Real val1, Real val2);
	  Real max(Real val1, Real val2);
	  Real clamp(Real val, Real min, Real max);
	  
	  int min(int val1, int val2);
	  int max(int val1, int val2);
	  int clamp(int val, int min, int max);
	};

};
#endif

