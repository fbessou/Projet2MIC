#ifndef _CANDY_SHIP_H_ 
#define _CANDY_SHIP_H_ 
#include "CandyCommon.h"
#include "CandyActor.h"
#include "CandyMeasureBar.h"
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
			void addLife(unsigned int life);
			const MeasureBar & getLifeBar() const;

			virtual bool update(const Real & ) override ;
			void forwardImpulse();
			void setSecondaryWeapon(Weapon * );
			void setPrimaryWeapon(BasicWeapon * );
			World * getWorld(){return mWorld;}
			
			void onCollision(Actor * actor);
			void beforeDrawing(sf::RenderTarget & ) override ;
			void onScore(const unsigned int & points);
			bool takeDamage(const Real & damages);
			const Team * getTeam()const {return mTeam;}
			Team * getTeam() {return mTeam;}
			const Vector & getAimDirection();
			
		protected:
			Real mMaxSpeed;
			Real mPeakTime;
			//Life management
			Real mLife;
			Real mMaxLife;
			sf::Texture * mTexture;
			Team * mTeam;
			BasicWeapon * mPrimaryWeapon;		
			Weapon * mSecondaryWeapon;		
			//Life HUD
			MeasureBar mLifeBar;
			Vector mAimDirection;
			Real mRecoveryTime;
		private :
			Vector getBaseRelativePosition() const;
	};

	class Particle : public Actor
	{
		public:
			Particle(const sf::Color & , const Vector & position, const Vector & velocity);
			virtual bool update(const Real & ) override;
		private:
			Real mTimeToLive;
	};
};


#endif 
