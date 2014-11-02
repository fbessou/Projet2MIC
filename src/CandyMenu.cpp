#include "CandyMenu.h"

using namespace Candy;
using namespace std;
using namespace sf;

MenuItem::MenuItem(string name, Vector2f position, unsigned int charSize, void (*function)()):
	mName(name),mPosition(position),mCharSize(charSize),mAction(function)
{
	mSelected = false;
}

MenuItem::~MenuItem(){
}

string MenuItem::getName()
{
	return mName;
}

Vector2f MenuItem::getPosition()
{
	return mPosition;
}

unsigned int MenuItem::getCharSize()
{
	return mCharSize;
}

bool MenuItem::getSelected()
{
	return mSelected;
}

void MenuItem::setSelected(bool s)
{
	mSelected = s;
}

void MenuItem::executeAction()
{
	mAction();
}



Menu::Menu(sf::RenderWindow * window,Game *game):
	mWindow(window)
{
	mFocused = false;

	mActiveColor = Color::White;
	mInactiveColor = Color(150,150,150);
	mDisabledColor = Color(90,90,90);

	mFont = game->getFont();
}

Menu::~Menu(){
}

void Menu::onSelected()
{
	if (mFocused)
		mActual->executeAction();
}

void Menu::moveUp()
{
	mActual->setSelected(false);
	if (mFocused)
	{
		if (mActual == mList.begin())
			mActual = mList.end()-1;
		else
			mActual--;
	}
	mActual->setSelected(true);
}

void Menu::moveDown()
{
	mActual->setSelected(false);
	if (mFocused)
	{
		if (mActual == mList.end()-1)
			mActual = mList.begin();
		else
			mActual++;
	}
	mActual->setSelected(true);
}

void Menu::addItem(MenuItem item)
{
	mList.push_back(item);
	// because the array is reallocated, we have to reinitialize the iterator
	mActual = mList.begin();
	mActual->setSelected(true);
}

void Menu::setFocused(bool f)
{
	mFocused = f;
}

void Menu::render()
{
	Text displayText;
	FloatRect textRect;
	displayText.setFont(mFont);

	for (vector<MenuItem>::iterator it = mList.begin(); it != mList.end(); it++)
	{
		displayText.setString(it->getName());

		displayText.setCharacterSize(it->getCharSize());

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
