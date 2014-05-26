#ifndef _BULLET_H_
#define _BULLET_H_

#include "CandyActor.h"
#include "CandyTeam.h"
namespace Candy
{
	class Bullet : public Actor
	{
		protected:
			Real mTimeToLive;
			bool mHitObstacle;
			Team * mTeam;
		public:
			Bullet(Team * team,const Vector & position, const Vector & velocity);
			~Bullet();
			virtual bool update(const Real & ) override;
			void onCollision(Actor * actor);
	};
};
#endif
