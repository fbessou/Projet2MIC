#include "CandyMenu.h"

using namespace Candy;
using namespace std;
using namespace sf;

CandyMenuItem::CandyMenuItem(string name,Vector2f position,callback_function function):
	mName(name),mPosition(position),mAction(function)
{
	mSelected = false;
}

CandyMenuItem::~CandyMenuItem(){
}

string CandyMenuItem::getName()
{
	return mName;
}

Vector2f CandyMenuItem::getPosition()
{
	return mPosition;
}

bool CandyMenuItem::getSelected()
{
	return mSelected;
}

void CandyMenuItem::setSelected(bool s)
{
	mSelected = s;
}

void CandyMenuItem::executeAction()
{
	mAction();
}



CandyMenu::CandyMenu(sf::RenderWindow * window,Game *game):
	mWindow(window)
{
	mFocused = false;

	mActiveColor = Color::White;
	mInactiveColor = Color(150,150,150);
	mDisabledColor = Color(90,90,90);

	mFont = game->getFont();
}

CandyMenu::~CandyMenu(){
}

void CandyMenu::onSelected()
{
	if (mFocused)
		mActual->executeAction();
}

void CandyMenu::moveUp()
{
	if (mFocused)
	{
		if (mActual == mList.begin())
			*mActual = mList.back();
		else
			mActual--;
	}
}

void CandyMenu::moveDown()
{
	if (mFocused)
	{
		if (mActual == mList.end()-1)
			mActual = mList.begin();
		else
			mActual++;
	}
}

void CandyMenu::addItem(CandyMenuItem item)
{
	mList.push_back(item);
	// because the array is reallocated, we have to reinitialize the iterator
	mActual = mList.begin();
	mActual->setSelected(true);
}

void CandyMenu::setFocused(bool f)
{
	mFocused = f;
}

void CandyMenu::render()
{
	Text displayText;
	FloatRect textRect;
	displayText.setFont(mFont);

	for (vector<CandyMenuItem>::iterator it = mList.begin(); it != mList.end(); it++)
	{
		displayText.setString(it->getName());

		if (it->getSelected())
			displayText.setColor(mActiveColor);
		else
			displayText.setColor(mInactiveColor);

		textRect = displayText.getLocalBounds();
		displayText.setOrigin(textRect.left+textRect.width/2.0f,textRect.top+textRect.height/2.0f);
		displayText.setPosition(it->getPosition());
		
		mWindow->draw(displayText);
	}
}
