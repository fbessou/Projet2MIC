#include "CandyMeasureBar.h"
#include <iostream>

using namespace Candy;

MeasureBar::MeasureBar(const sf::Color & frontCol, const sf::Color & backCol, const Vector & size,const Real & value):
	mValue(0),mSize(size),mFrontColor(frontCol),mBackColor(backCol),
	mFrontRectangle(size),mBackRectangle(size)

{
	mFrontRectangle.setFillColor(mFrontColor);
	mBackRectangle.setFillColor(mBackColor);
}
MeasureBar::~MeasureBar()
{
}

void MeasureBar::setPosition(const Vector & position)
{
	mFrontRectangle.setPosition(position-mSize/2);
	mBackRectangle.setPosition(position-mSize/2);
}

void MeasureBar::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mBackRectangle,states);
	target.draw(mFrontRectangle,states);
}

void MeasureBar::setValue(const Real & value)
{
	mFrontRectangle.setSize(sf::Vector2f{mSize.x*Math::clamp(value,0.,1.),mSize.y});
}


