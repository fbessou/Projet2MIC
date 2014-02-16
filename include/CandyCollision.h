#ifndef _CANDY_COLLISION_H_
#define _CANDY_COLLISION_H_
#include "CandyCollision.h"
namespace Candy
{
	class CollisionManager
	{
		private:

			typedef std::list<Actor*> ActorList;
			std::map<CollisionMask, ActorList >;

		public:

			CollisionManager();
			~CollisionManager();

			void update();
			void addActor(Actor* actor);
			void removeActor(Actor* actor); // TODO raise an exception

	};

}; // namespace Candy
#endif
