#ifndef _CANDY_TEAM_H_
#define _CANDY_TEAM_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "CandyMath.h"
#include "CandySettings.h"
namespace Candy
{
	class Team
	{
		public:
			const Vector shipBase;
			const Vector direction;
			KeyBinding keys;
			const sf::Color color;
		protected:
			unsigned int mScore;
			Ship * mShip;
		public:
			Team(const sf::Color &,const Vector &, const Vector &, const KeyBinding & );

			const unsigned int & getScore() const;
			void score (const unsigned int &);
			Ship * getShip(){return mShip;}

	};
};
#endif
