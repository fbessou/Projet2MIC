#ifndef _CANDY_COLLISION_H_
#define _CANDY_COLLISION_H_

#include "CandyCollision.h"

namespace Candy
{
	class World
	{
		private:

			typedef std::list<Actor*> ActorList;
			std::map<CollisionMask, ActorList >;

		public:

			World();
			~World();

			void update();
			void addActor(Actor* actor);
			void removeActor(Actor* actor); 

	};

}; // namespace Candy

#endif
