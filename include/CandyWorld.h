#ifndef _CANDY_WORLD_H_
#define _CANDY_WORLD_H_

#include "CandyCommon.h"
#include "CandyActor.h"
#include "CandyBody.h"
#include <set>

namespace Candy
{
	class World
	{
		private:

			std::set<Actor*> mActors;
			bool _collisionRectangleRectangle(const Actor * a1,const Actor * a2) const;
			bool _collisionRectangleConvex(const Actor * a1,   const Actor * a2) const ;
			bool _collisionRectangleCircle(const Actor * a1,   const Actor * a2)const ;
			bool _collisionCircleConvex(const Actor * a1,      const Actor * a2)const ;
			bool _collisionCircleCircle(const Actor * a1,      const Actor * a2)const ;
			bool _collisionConvexConvex(const Actor * a1,      const Actor * a2)const ;
			bool testCollision(const Actor * , const Actor * );
		public:

			World();
			~World();

			void update();
			void addActor(Actor* actor);
			bool removeActor(Actor* actor); 
			void step(unsigned int );
	};

}; // namespace Candy

#endif
