#ifndef _CANDY_SHIP_H_ 
#define _CANDY_SHIP_H_ 
#include "CandyCommon.h"
#include "CandyActor.h"
#include "CandyGame.h"
#include "CandyWeapon.h"

namespace Candy
{
	class Ship : public Actor
	{
		public:
			Ship(Team & owner);
			~Ship();
			void setLife();
			unsigned short getLife();
		protected:
			unsigned short mLife;
			Team  mTeam;
			Weapon  mWeapon;
			
	};
};
#endif 
