
#include "CandyMath.h"
#include "CandyWorld.h"
using namespace Candy;

World::World()
{

}

World::~World()
{

	//Destroy all actors remaining
}

void World::step( unsigned int)
{

}

void World::addActor(Actor * actor)
{
	mActors.insert(actor);
}

bool World::removeActor(Actor * actor)
{
	if(false)
		return false;

	return true;
}


