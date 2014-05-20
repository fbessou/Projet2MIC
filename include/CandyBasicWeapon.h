#ifndef _CANDY_BASIC_WEAPON_H_
#define _CANDY_BASIC_WEAPON_H_
#include "CandyWeapon.h"
namespace Candy
{
	class BasicWeapon : public Weapon
	{
		protected:
			unsigned int fire();
		public:
		BasicWeapon(Ship * );
		~BasicWeapon();
		friend Ship;
		
	};
};
#endif
