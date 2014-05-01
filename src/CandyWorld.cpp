#include <iostream>
#include "CandyMath.h"
#include "CandyWorld.h"
using namespace Candy;

World::World(sf::RenderTarget * renderTarget): mRenderTarget(renderTarget)
{

}

World::~World()
{

	//Destroy all actors remaining
}

void World::step( const Real & elapsedTime)
{
	//test collision for each Actor
	for(auto itActor1 = mActors.begin() ; itActor1 != mActors.end() ;)
	{
		if((*itActor1)->update(elapsedTime))
		{
			if(!(*itActor1)->isGhost())
			for(auto itActor2 = itActor1; ++itActor2 != mActors.end();)
			{
				testCollision(**itActor1, **itActor2);
			}
			itActor1++;
		}
		else
		{
			delete (*itActor1);
			itActor1=mActors.erase(itActor1);
		}
			
	}
}

Actor * World::addActor(Actor * actor)
{
	mActors.insert(actor);
	actor->_onOwnerChanged(this);
	return actor;
}

void World::render() const
{
	for(auto it = mActors.begin(); it!=mActors.end();it++)
	{
		(*it)->draw(*mRenderTarget);
	}
}

Actor * World::removeActor(Actor * actor)
{
	if(false)
		return actor;

	return actor;
}

//Private member functions

bool World::testCollision(const Actor& actor1,const Actor & actor2)
{
	const Body * b1=actor1.getBody();
	const Body * b2=actor2.getBody();

	switch(b1->getType())
	{
		case Body::RECTANGLE:
			switch(b2->getType())
			{
				case Body::RECTANGLE:
					return _collisionRectangleRectangle(actor1,actor2);
				case Body::CIRCLE:
					return _collisionRectangleCircle(actor1,actor2);
				case Body::CONVEX_HULL:
					return _collisionRectangleConvex(actor1,actor2);
			}
			break;
		case Body::CIRCLE:
			switch(b2->getType())
			{
				case Body::RECTANGLE:
					return _collisionRectangleCircle(actor2,actor1);
				case Body::CIRCLE:
					return _collisionRectangleCircle(actor1,actor2);
				case Body::CONVEX_HULL:
					return _collisionCircleConvex(actor1,actor2);

			}
			break;
		case Body::CONVEX_HULL:
			switch(b2->getType())
			{
				case Body::RECTANGLE:
					return _collisionRectangleConvex(actor2,actor1);
				case Body::CIRCLE:
					return _collisionCircleConvex(actor1,actor2);
				case Body::CONVEX_HULL:
					return _collisionConvexConvex(actor1,actor2);
			}
			break;	
	}
	return true;
}

bool World::_collisionRectangleRectangle(const Actor & a1,const Actor & a2) const
{
	return true;
}
bool World::_collisionRectangleConvex(const Actor & a1,   const Actor & a2) const
{
	return true;
}
bool World::_collisionRectangleCircle(const Actor & a1,   const Actor & a2)const 
{
	return true;
}
bool World::_collisionCircleConvex(const Actor & a1,      const Actor & a2)const 
{
	return true;
}
bool World::_collisionCircleCircle(const Actor & a1,      const Actor & a2)const 
{
	Real sqDist = (a1.getPosition()-a2.getPosition()).squaredLength();
	Real sqSumOfRadius = (a1.getBody()->getCircle().radius+a2.getBody()->getCircle().radius);
	sqSumOfRadius*=sqSumOfRadius;
	return sqDist<=sqSumOfRadius;
}
bool World::_collisionConvexConvex(const Actor & a1,      const Actor & a2)const 
{
	return true;
}
