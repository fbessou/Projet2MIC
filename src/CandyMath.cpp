#include "CandyMath.h"
#include <cmath>

using namespace Candy;

bool Vector::isNormalised() const {
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

Vector Vector::operator+(const Vector & v) const {
  return {x+v.x, y+v.y};
}

Vector Vector::operator-(const Vector & v) const {
  return {x-v.x, y-v.y};
}

Vector Vector::operator*(const Real & r) const {
  return {r*x, r*y};
}
