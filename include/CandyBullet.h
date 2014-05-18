#ifndef _BULLET_H_
#define _BULLET_H_

#include "CandyActor.h"
namespace Candy
{
	class Bullet : public Actor
	{
		protected:
			Real mTimeToLive;
			bool mHitObstacle;
		public:
			Bullet(const Vector & , const Vector & );
			~Bullet();
			virtual bool update(const Real & ) override;
			void onCollision(Actor * actor);
	};
};
#endif
