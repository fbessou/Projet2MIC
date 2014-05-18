#ifndef _CANDY_SHIP_H_ 
#define _CANDY_SHIP_H_ 
#include "CandyCommon.h"
#include "CandyActor.h"
#include "CandyGame.h"
#include "CandyTeam.h"
namespace Candy
{
	class Ship;
}
#include "CandyWeapon.h"

namespace Candy
{
	class Ship : public Actor
	{
		public:
			Ship(Team * owner, unsigned int maxLife);
			~Ship();
			void setLife(unsigned int life);
			unsigned int getLife() const;
			
			void setMaxLife(unsigned int newMax);
			virtual bool update(const Real & ) override ;
			void forwardImpulse();
			void setSecondaryWeapon(Weapon * );
			void setPrimaryWeapon(Weapon * );
			World * getWorld(){return mWorld;}
			
			void onCollision(Actor * actor);
		protected:
			Real mMaxSpeed;
			Real mPeakTime;
			unsigned int mLife;
			unsigned int mMaxLife;
			sf::Texture * mTexture;
			Team * mTeam;
			Weapon * mPrimaryWeapon;		
			Weapon * mSecondaryWeapon;		
		private :
			Vector getBaseRelativePosition() const;
			const Vector mLateralDirection;
	};
};
#endif 
