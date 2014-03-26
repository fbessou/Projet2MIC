#include "CandyShip.h"
#include "CandyMath.h"

using namespace Candy;

Ship::Ship(/*Team & owner,*/ unsigned int maxLife) : Actor("Ship",Vector(0,0))
{
  // mTeam = Team;
  mMaxLife = maxLife;
}

Ship::~Ship()
{
}

void Ship::setLife(unsigned int life)
{
  mLife = Math::clamp(life,0,mMaxLife);
}

unsigned int Ship::getLife()
{
  return mLife;
}

void Ship::setMaxLife(unsigned int newMax)
{
  mMaxLife = newMax;
}
