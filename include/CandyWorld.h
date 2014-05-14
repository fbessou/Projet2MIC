#ifndef _CANDY_WORLD_H_
#define _CANDY_WORLD_H_

#include "SFML/Graphics.hpp"
#include "CandyCommon.h"
namespace Candy
{
	class World;
}
#include "CandyActor.h"
#include "CandyBody.h"
#include <set>
#include <map>
namespace Candy
{
	class World
	{
		private:
			//this set contains all actors in the scene.
			std::set<Actor*, ActorComparator> mActors;
			sf::RenderTarget * mRenderTarget;
			bool _collisionRectangleRectangle(const Actor & a1,const Actor & a2) const;
			bool _collisionRectangleConvex(const Actor & a1,   const Actor & a2) const ;
			bool _collisionRectangleCircle(const Actor & a1,   const Actor & a2)const ;
			bool _collisionCircleConvex(const Actor & a1,      const Actor & a2)const ;
			bool _collisionCircleCircle(const Actor & a1,      const Actor & a2)const ;
			bool _collisionConvexConvex(const Actor & a1,      const Actor & a2)const ;
			bool testCollision(const Actor & , const Actor & );
			bool requireCollision(const std::string & );
		public:

			World(sf::RenderTarget * target);
			~World();
			static int registerActorType();

			Actor * addActor(Actor* actor); 
			void render() const;
			Actor* removeActor(Actor* actor); //returns the instance removed from the scene. The actor still exists and you are 
			void step(const Real &  );
	};

}; // namespace Candy

#endif
