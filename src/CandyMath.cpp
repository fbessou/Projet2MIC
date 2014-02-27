#include "CandyMath.h"
#include <cmath>
#include <ostream>

using namespace Candy;

const Vector Vector::UNIT_X(1.0, 0.0);
const Vector Vector::UNIT_X(0.0, 1.0);

Vector::Vector(const Real & a, const Real & b){
  x = a;
  y = b;
}

Vector::~Vector(){}

bool Vector::isNormalized() const {
  return length()==1;
}

void Vector::normalize(){
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

Vector Vector::operator*(const Real & r) const {
  return {r*x, r*y};
}

Vector Vector::operator/(const Real & r) const {
  return {x/r, y/r};
}

const Vector & Vector::operator=(const Vector & v){
  x=v.x;
  y=v.y;
}

const Vector & Vector::operator+=(const Vector & v){
  x+=v.x;
  y+=v.y;
}

const Vector & Vector::operator-=(const Vector & v){
  x-=v.x;
  y-=v.y;
}

const Vector & Vector::operator*=(const Real & v){
  x*=v;
  y*=v;
}

const Vector & Vector::operator/=(const Real & v){
  x/=v;
  y/=v;
}

std::ostream& operator<<(std::ostream& stream, const Vector& v){
  stream<<"Vector("<<v.x<<","<<v.y<<")";
  return stream;
}
