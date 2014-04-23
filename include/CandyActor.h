#ifndef _CANDY_ACTOR_H_
#define _CANDY_ACTOR_H_

#include "CandyCommon.h"
#include "CandyBody.h"
#include "CandyMath.h"
#include <SFML/Graphics.hpp>
namespace Candy
{
	class Actor{
		private:
			const std::string mType;
			Vector mPosition;
			Vector mVelocity;
			sf::Sprite * mSprite;
		protected:


			Body * mBody;
			bool mGhost;
			bool mVisible;
			//bool mSameTypeCollision;
			virtual ~Actor();

			void setSprite(sf::Sprite * sprite);
			inline sf::Sprite * getSprite(){return mSprite;}

		public:
			Actor(const string type, const Vector & position, Body * body, const Vector & velocity = Vector(0,0),const bool & ghost = false,const bool & visible = true);
			virtual void update(const Real & );
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
