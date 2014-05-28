#include "CandyTeam.h"
#include "CandyShip.h"
#include <iostream>
using namespace Candy;
using namespace sf;

Team::Team(const Color & _color,const Vector & base,const Vector & dir, const KeyBinding & keyConf):
	shipBase(base),
	direction(dir), 
	keys(keyConf),
	color(_color),
	mScore(0)
{
	mShip = new Ship(this,500);

}
void Team::score(const unsigned int & points)
{
	mScore+=points;
	std::cout<<"score : "<<mScore<<std::endl;
	mShip->onScore(mScore);
}

void Team::setOpponent(Team * team)
{
	mOpponent=team;
}

Team * Team::getOpponent()
{
	return mOpponent;
}
