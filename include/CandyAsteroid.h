#ifndef _CANDY_ASTEROID_H_
#define _CANDY_ASTEROID_H_

#include "CandyCommon.h"
#include "CandyActor.h"
#include "CandyBonus.h"
namespace Candy
{
	class Asteroid : public Actor
	{
		public:
			Asteroid(World * world,const Vector & position,const Vector & velocity);
			~Asteroid();
			bool update(const Real & timeSinceLastFrame);
			void onCollision(Actor * actor);
		private:
			bool mHit;
			World *mWorld;
			const Real mAngularVelocity;
			Real mImplodeAnimationTime;
			Bonus::Type mBonus;


	};
};

#endif

