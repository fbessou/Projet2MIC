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

		// TO DO load from file & save from SettingsMenu ?
		cout<<"Loading Parameters"<<endl;
	}else{
		// then load the default profile
		mBinding1={sf::Keyboard::C,
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
}
