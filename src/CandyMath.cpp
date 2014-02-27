#include "CandyMath.h"
#include <cmath>

using namespace Candy;
Vector::Vector(const Real & _x, const Real & _y): x(_x), y(_y){}

Vector::~Vector(){}
bool Vector::isNormalised() const {
  return length()==1;
}


void Vector::normalise(){
  Real norme = length();
  x=x/norme;
  y=y/norme;
}

Real Vector::length() const {
  return sqrt(x*x+y*y);
}

Vector Vector::operator+(const Vector & v) const {
  return {x+v.x, y+v.y};
}

Vector Vector::operator-(const Vector & v) const {
  return {x-v.x, y-v.y};
}

Vector Vector::operator*(const Real & r) const {
  return {r*x, r*y};
}

const Vector & Vector::operator=(const Vector & vect)
{
	x=vect.x;
	y=vect.y;
	return *this;
}


const Vector & Vector::operator+=(const Vector & vect)
{
	x+=vect.x;
	y+=vect.y;
	return *this;
}

const Vector & Vector::operator-=(const Vector & vect)
{
	x-=vect.x;
	y-=vect.y;
	return *this;
}

const Vector & Vector::operator*=(const Real & k)
{
	x*=k;
	y*=k;
	return *this;
}

const Vector & Vector::operator/=(const Real & k)
{
	x/=k;
	y/=k;
	return *this;
}
