#include "CandyMath.h"
#include <cmath>
#include <ostream>
#include <sstream>
#include <iostream>
using namespace Candy;

const Vector Vector::UNIT_X(1.0, 0.0);
const Vector Vector::UNIT_Y(0.0, 1.0);

Vector::Vector(): x(0), y(0){}
Vector::Vector(const Real & _x, const Real & _y): x(_x), y(_y){}
Vector::Vector(const sf::Vector2f & v): x(v.x), y(v.y){}
Vector::Vector(const sf::Vector2u & v): x(v.x), y(v.y){}
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

Vector::operator std::string() const
{
	std::stringstream ss;
	ss<<"( "<<x<<", "<<y<<" )";
	return ss.str();
}
Vector Vector::rotated(Real angle, const Math::AngleMode & mode) const
{
	angle=(mode==Math::DEGREE ? angle/180*Math::PI : angle);
	return Vector(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
}

Vector Vector::operator-() const 
{
	return Vector(-x,-y);
}

Vector::operator sf::Vector2f() const
{
	return sf::Vector2f(x,y);
}

void Vector::negate()
{
	x=-x;
	y=-y;
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

Real Candy::dot(const Vector & vect1,const Vector & vect2)
{
	return vect1.x*vect2.x+vect1.y*vect2.y;
}

Vector Candy::tripleProduct(const Vector & a,const Vector & b, const Vector & c)
{
	//Vector result = b*dot(a,c)-c*dot(a,b);
	Vector result = b*dot(a,c)-a*dot(c,b);
	return result;
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

Vector Vector::directOrthogonal() const
{
	return Vector(-y,x);
}

bool Vector::operator==(const Vector & vect)
{
	return (x==vect.x && y==vect.y);
}

bool Vector::operator<(const Vector & vect)
{
	return (x<vect.x) || (y<vect.y);
}

std::ostream& Candy::operator<<(std::ostream& stream, const Vector& v){
  stream<<(std::string)v;
  return stream;
}

Real Math::atan2(Real y , Real x)
{
	return ::atan2(y,x);
}

Real Math::min(Real val1, Real val2)
{
  return val1<val2 ? val1 : val2;
}

Real Math::max(Real val1, Real val2)
{
  return val1>val2 ? val1 : val2;
}

Real Math::clamp(Real val, Real min, Real max)
{
  return Math::max(Math::min(val,max),min);
}

int Math::min(int val1,int val2)
{
  return val1<val2 ? val1 : val2;
}

int Math::max(int val1, int val2)
{
  return val1>val2 ? val1 : val2;
}

Math::IntURNG Math::IntURNG::random0_255(0,255);
Math::RealURNG Math::RealURNG::random0_1(0,1);
