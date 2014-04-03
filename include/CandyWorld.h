#ifndef _CANDY_WORLD_H_
#define _CANDY_WORLD_H_

#include "CandyCommon.h"
#include "CandyActor.h"
#include "CandyBody.h"
#include <set>
#include <map>
namespace Candy
{
	class World
	{
		private:
			//this map contains all actors in the scene.
			//We choose to make a map with ActorType as key to check if one actor must test collision with others.
			//std::map<ActorType,std::vector<Actor*>> mActors;
			std::set<Actor*> mActors;
			bool _collisionRectangleRectangle(const Actor & a1,const Actor & a2) const;
			bool _collisionRectangleConvex(const Actor & a1,   const Actor & a2) const ;
			bool _collisionRectangleCircle(const Actor & a1,   const Actor & a2)const ;
			bool _collisionCircleConvex(const Actor & a1,      const Actor & a2)const ;
			bool _collisionCircleCircle(const Actor & a1,      const Actor & a2)const ;
			bool _collisionConvexConvex(const Actor & a1,      const Actor & a2)const ;
			bool testCollision(const Actor & , const Actor & );
			bool requireCollision(const string & );
		public:

			World();
			~World();
			static int registerActorType();

			void update();
			void addActor(Actor* actor); 
			Actor* removeActor(Actor* actor); //returns the instance removed from the scene. The actor still exists and you are 
			void step(unsigned int );
	};

}; // namespace Candy

#endif
