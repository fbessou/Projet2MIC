#ifndef _CANDY_MATH_H_
#define _CANDY_MATH_H_

#include <SFML/System/Vector2.hpp>
#include "CandyCommon.h"
#include <random>
#include <ostream>

namespace Candy
{
	namespace Math
	{
		Real min(Real val1, Real val2);
		Real max(Real val1, Real val2);
		Real clamp(Real val, Real min, Real max);
		Real atan2(Real y,Real x);
		int min(int val1, int val2);
		int max(int val1, int val2);
		int clamp(int val, int min, int max);

		const Real PI=3.14159263358979;

		enum AngleMode
		{
			DEGREE,
			RADIAN
		};

		class RealURNG
		{
			private:
				std::random_device rd;
				std::mt19937 mSeed;
				std::uniform_real_distribution<Real> mDistribution;
				static RealURNG random0_1;
			public:
				RealURNG(Real min, Real max):rd(), mSeed(rd()),mDistribution(min,max){}
				Real operator()(){return mDistribution(mSeed);}
				static Real normalised(){return random0_1();}
		};

		class IntURNG
		{
			private:
				std::random_device rd;
				std::mt19937 mSeed;
				std::uniform_int_distribution<> mDistribution;
				static IntURNG random0_255;
			public:
				IntURNG(int min, int max):rd(), mSeed(rd()),mDistribution(min,max){}
				int operator()(){return mDistribution(mSeed);}
				static int randomByte(){return random0_255();}
		};
	};
	class Vector
	{
		public:
			Real x,y;
		public:
			Vector();
			Vector(const Real & ,const Real &);
			~Vector();

			bool isNormalised() const;
			void normalise(); 
			Vector normalisedCopy() const;


			Real dotProduct(const Vector & ) const;
			Vector rotated(const Real & , const Math::AngleMode &) const;
			Vector operator-() const;
			Vector operator+(const Vector & ) const;
			Vector operator-(const Vector &) const;
			Vector operator/(const Real &) const;


			const Vector & operator=(const Vector &);
			const Vector & operator+=(const Vector &);
			const Vector & operator-=(const Vector &);
			const Vector & operator*=(const Real &);
			const Vector & operator/=(const Real &);
			Vector directOrthogonal() const;
			bool operator==(const Vector &);
			bool operator<(const Vector &);
			//Real angleBetween(Vec)
			Real length() const; // return the magnitude of the vector
			Real squaredLength() const; // return the squared magnitude of the vector (much faster)
			operator std::string() const;
			operator sf::Vector2f()const;
		
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


};
#endif

