#ifndef _CANDY_WORLD_H_
#define _CANDY_WORLD_H_

#include "CandyCommon.h"
#include "CandyActor.h"
#include <set>

namespace Candy
{
	class World
	{
		private:

			std::set<Actor*> mActors;

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
