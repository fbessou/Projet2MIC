#ifndef _CANDY_ROCKET_LAUNCHER_H_
#define _CANDY_ROCKET_LAUNCHER_H_

#include "CandyCommon.h"
#include "CandyWeapon.h"

namespace Candy
{
	class Rocket : public Actor
	{
		public:
			Rocket(Team * owner, const Vector & position, const Vector & direction, const Actor * target);
			bool update(const Real & timeSinceLastFrame) override;
			void onCollision(Actor * actor) override;
			const unsigned int & getDamages()const {return mDamagesInflicted;}
			
			Team * getTeam();
		protected:
			const Actor * mTarget;
			Real mTimeToLive;
			bool mDestroyed;
			Team * mTeam;
			Real mMaxScale;
			unsigned int mDamagesInflicted;
			bool mAnimate;
		
	};

	class RocketLauncher : public Weapon
	{
		public :
			RocketLauncher(Ship *);
			~RocketLauncher();

			void draw(sf::RenderTarget & );
		protected:
			sf::Sprite mRocketSprite;
			unsigned int fire() override;
	};
};

#endif
