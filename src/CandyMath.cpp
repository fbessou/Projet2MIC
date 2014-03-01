#include "CandyMath.h"
#include <cmath>
#include <ostream>

using namespace Candy;

const Vector Vector::UNIT_X(1.0, 0.0);
const Vector Vector::UNIT_Y(0.0, 1.0);

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

Real Vector::squaredLength() const {
  return x*x+y*y;
}

Vector Vector::operator+(const Vector & v) const {
  return {x+v.x, y+v.y};
}

Vector Vector::operator-(const Vector & v) const {
  return {x-v.x, y-v.y};
}

Vector Candy::operator*(const Vector & v,const Real & r)
{
  return {r*v.x, r*v.y};
}

Vector Candy::operator*(const Real & r, const Vector & v)
{
  return {r*v.x, r*v.y};
}

Vector Vector::operator/(const Real & r) const
{
  return {x/r, y/r};
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

std::ostream& Candy::operator<<(std::ostream& stream, const Vector& v){
  stream<<"Vector("<<v.x<<","<<v.y<<")";
  return stream;
}
