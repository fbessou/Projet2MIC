#include "CandySettings.h"
#include <iostream>
#include <fstream>

using namespace Candy;
using namespace std;

Settings::Settings()
{
	ifstream myParam;
	myParam.open("./params.conf");
	if (myParam.is_open())
	{
		int a;
		// TO DO load from file & save from SettingsMenu ?
		cout<<"Loading Parameters"<<endl;
		myParam>>a;
		mBinding1.primary=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding1.secondary=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding1.left=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding1.right=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding1.forward=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding2.primary=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding2.secondary=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding2.left=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding2.right=(sf::Keyboard::Key)a;
		myParam>>a;
		mBinding2.forward=(sf::Keyboard::Key)a;
		myParam.close();
	}else{
		// then load the default profile
		loadDefault();
	}
}

void Settings::loadDefault()
{
		mBinding1={sf::Keyboard::LShift,
				sf::Keyboard::V,
				sf::Keyboard::D,
				sf::Keyboard::Q,
				sf::Keyboard::S};

		mBinding2={sf::Keyboard::RShift,
				sf::Keyboard::LSystem,
				sf::Keyboard::Left,
				sf::Keyboard::Right,
				sf::Keyboard::Up};

}

void Settings::saveSettings()
{
	remove("./params.conf");
	ofstream myParam;
	myParam.open("./params.conf");
	myParam<<(int)mBinding1.primary<<endl;
	myParam<<(int)mBinding1.secondary<<endl;
	myParam<<(int)mBinding1.left<<endl;
	myParam<<(int)mBinding1.right<<endl;
	myParam<<(int)mBinding1.forward<<endl;
	myParam<<(int)mBinding2.primary<<endl;
	myParam<<(int)mBinding2.secondary<<endl;
	myParam<<(int)mBinding2.left<<endl;
	myParam<<(int)mBinding2.right<<endl;
	myParam<<(int)mBinding2.forward<<endl;
	myParam.close();
}
