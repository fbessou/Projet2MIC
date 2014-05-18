#ifndef _CANDY_ACTOR_H_
#define _CANDY_ACTOR_H_

#include "CandyCommon.h"
#include "CandyMath.h"
#include <SFML/Graphics.hpp>
namespace Candy
{
class Actor;
class ActorComparator
{
	public:
	bool operator()(const Actor * a1, const Actor * a2);
};
};
#include "CandyBody.h"
#include "CandyWorld.h"
namespace Candy
{
	/*
	 * @class Actor
	 * @brief A class representing a visible or invisible entity that may be drawn in a sf::Window;
	 * 
	 * Once created, an Actor can be added to a World, which is a set of Actor that can collide, 
	 * each actor has two main properties :
	 * - A body (its hull)
	 * - A texture
	 * 
	 * If an Actor is owned by a World, its update process is called automatically on the world instance's update.
	 * 
	 */
	class Actor{
		private:
			/*
			 * @
			 */
			const std::string mType;
			/*
			 * @
			 */
			Vector mPosition;
			/*
			 * @
			 */
			static unsigned long currentActorId;
		protected:
			sf::Sprite * mSprite;
			World * mWorld;
			Vector mVelocity;
			Body * mBody;
			bool mGhost;
			bool mVisible;
			//bool mSameTypeCollision;

			void setTexture(const sf::Texture & texture);
			inline sf::Sprite * getSprite(){return mSprite;}

			/* public attributes*/
			const unsigned int & mLayer;
		public:
			Actor(const std::string type, const Vector & position, Body * body, const Vector & velocity = Vector(0,0), const unsigned int & layer = 0, const bool & ghost = false,const bool & visible = true);
			virtual ~Actor();

			void _onOwnerChanged(World * owner );


			virtual bool update(const Real & );

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

			void move(const Vector&, const TransformSpace & = TS_WORLD);
			void rotate(const Real & angle, const Math::AngleMode & = Math::DEGREE);

			Real getRotation(const Math::AngleMode & = Math::DEGREE);

			Vector  getDirectionVector();

			virtual void onCollision(Actor * actor);

		public:
			friend ActorComparator;

	}; // class Actor

}; // namespace Candy
#endif
