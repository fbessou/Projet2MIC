#ifndef _CANDY_WEAPON_H_
#define _CANDY_WEAPON_H_
namespace Candy
{

	class Weapon;
};
#include "CandyShip.h"

namespace Candy
{
	class Weapon
	{
		protected:
			/**
			 * ship which own this Weapon
			 */
			Ship * mOwner; 
			/**
			 * number of round of ammunition
			 */
			unsigned int mAmmoStock;
			/**
			 * rounds fired by second 
			 */
			Real mFireRate;
			/**
			 * time to wait to be able to fire again
			 */
			Real mTimeBeforeNextShoot;
			/**
			 * fire 
			 */
			virtual unsigned int fire() = 0;

		public:
			Weapon(Ship *, const unsigned int &, const Real & );
			virtual ~Weapon();
			bool tryFiring(const Real &);
			const Real & getFireRate() const ;
			virtual void draw(sf::RenderTarget &){};

	};
};
#endif
