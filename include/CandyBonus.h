#ifndef _BONUS_H_
#define _BONUS_H_
#include "CandyActor.h"

namespace Candy
{
	class Bonus: public Actor
	{
		protected:
			Real mTimeToLive;
		public:
			Bonus(const Vector & position, const sf::Color &);
			~Bonus();
			enum Type
			{
				None,
				Rocket,
				Mega,
				Life
			};
			virtual bool update(const Real &) override;
	};

};

#endif
