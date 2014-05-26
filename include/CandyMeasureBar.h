#ifndef _CANDY_MEASURE_BAR_H_
#define _CANDY_MEASURE_BAR_H_
#include <SFML/Graphics.hpp>
#include "CandyMath.h"
namespace Candy
{
	class MeasureBar : public sf::Drawable
	{
		public:
			MeasureBar(const sf::Color & frontCol, const sf::Color & backCol, const Vector & size, const Real & value = 1);
			~MeasureBar();
			void setPosition(const Vector & position);
			void draw(sf::RenderTarget & target, sf::RenderStates states) const;
			void setValue( const Real & ratio );
		private:
			Real mValue;
			Vector mSize;
			sf::Color mFrontColor;
			sf::Color mBackColor;
			sf::RectangleShape mFrontRectangle;
			sf::RectangleShape mBackRectangle;
			
	};
};

#endif
