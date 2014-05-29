#ifndef _CANDY_BASIC_WEAPON_H_
#define _CANDY_BASIC_WEAPON_H_
#include "CandyCommon.h"
#include "CandyWeapon.h"
namespace Candy
{
	class BasicWeapon : public Weapon
	{
		protected:
			unsigned short mCounter;
			unsigned int mLevel;
			Real  mStep;
			unsigned int mNextLevelScore;
			unsigned int mCurrentLevelScore;
			Real mShotSpeed;
			void improve();
			void changeFireRate();
			unsigned int fire();
		public:
		BasicWeapon(Ship * );
		void onScore(const Real & );
		~BasicWeapon();

		friend Ship;
		
	};
};
#endif
