#ifndef _CANDY_TEAM_H_
#define _CANDY_TEAM_H_
#include <SFML/Window.hpp>
#include "CandyMath.h"
namespace Candy
{
	struct KeyBinding2
	{
		sf::Keyboard::Key primary;
		sf::Keyboard::Key secondary;
		sf::Keyboard::Key left;
		sf::Keyboard::Key right;
		sf::Keyboard::Key forward;
	};
	class Team
	{
		protected:
			unsigned int mScore;
		public:
			const Vector shipBase;
			const Vector direction;
			KeyBinding keys;

		public:
			Team(const Vector &, const Vector &, const KeyBinding & );
			const unsigned int & getScore() const;
			void score (const unsigned int &);

	};
};
#endif
