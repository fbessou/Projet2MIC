#ifndef _CANDY_ACTOR_H_
#define _CANDY_ACTOR_H_

#include "CandyCommon.h"
#include "CandyBody.h"
#include "CandyMath.h"
#include <SFML/Graphics.hpp>
namespace Candy
{
	class Actor{
		protected:
			const std::string mType;
			Vector mPosition;
			Vector mVelocity;
		protected:

			union
			{
				sf::Drawable * mDrawable;
				sf::Transformable * mTransformable;
			};

			Body * mBody;
			bool mGhost;
			bool mVisible;
			//bool mSameTypeCollision;
			virtual ~Actor();

		public:
			Actor(const string type, const Vector & position, const Vector & velocity = Vector(0,0),const bool & ghost = false,const bool & visible = true);
			void update(unsigned int);
			void draw(sf::RenderTarget & );
			
			const Body * getBody() const;
			void setBody(Body * mBody);

			std::string getType() const;
			
			const bool& isVisible() const ;
			void setVisible(const bool & visible);

			const bool& isGhost() const ;
			void setGhost(const bool & ghost);

			const Vector& getPosition() const;
			void setPosition(const Vector& );

			const Vector& getVelocity() const;
			void setVelocity(const Vector&);

			virtual void onCollision(Actor * actor);
			
	}; // class Actor

}; // namespace Candy
#endif
