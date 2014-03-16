#ifndef _CANDY_ACTOR_H_
#define _CANDY_ACTOR_H_

#include "CandyCommon.h"
#include "CandyBody.h"
#include "CandyMath.h"

namespace Candy
{
	class Actor{
		private:
			const std::string mType;
			Vector mPosition;
			Vector mVelocity;
		protected:
			Body * mBody;
			bool mGhost;
			bool mVisible;
			//bool mSameTypeCollision;
			virtual ~Actor()=0;

		public:
			Actor(const string type, const Vector & position, const Vector & velocity,const bool & ghost,const bool & visible);
			void update(unsigned int);
			void draw();
			
			std::string getType() const;
			
			const bool& isVisible() const ;
			void setVisible(const bool & visible);

			const bool& isGhost() const ;
			void setGhost(const bool & ghost);

			const Vector& getPosition() const;
			void setPosition(const Vector& );

			const Vector& getVelocity() const;
			void setVelocity(const Vector&);
			
	}; // class Actor

}; // namespace Candy
#endif
