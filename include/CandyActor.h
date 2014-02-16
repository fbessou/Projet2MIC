#ifndef _CANDY_ACTOR_H_
#define _CANDY_ACTOR_H_
#include "CandyCollision.h"
namespace Candy
{
	class Actor{
		private:
			virtual ~Actor()=0;

		protected:
			// vect mPosition;
			// vect mVelocity;
			// shape* mShape;

		public:
			Actor(/* vect position, vect velocity, CollisionMask mask */);
			void update();
			void draw();
			const CollisionMask & getCollisionMask() const ;
			void setCollisionMask(Candy::CollisionMask) ;

			// vect getPosition() const;
			// void setPosition(const vect  );

			// vect getVelocity() const;
			// void setVelocity(const vect  );
			//
	}; // class Actor

}; // namespace Candy
#endif
