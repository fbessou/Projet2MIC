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
		mBinding1={sf::Keyboard::C,
				sf::Keyboard::V,
				sf::Keyboard::D,
				sf::Keyboard::Q,
				sf::Keyboard::S};

		mBinding2={sf::Keyboard::L,
				sf::Keyboard::M,
				sf::Keyboard::Left,
				sf::Keyboard::Right,
				sf::Keyboard::Up};

}

void Settings::saveSettings(KeyBinding k1,KeyBinding k2)
{
	cout<<"Saving..."<<endl;
	remove("./params.conf");
	ofstream myParam;
	myParam.open("./params.conf");
	myParam<<(int)k1.primary<<endl;
	myParam<<(int)k1.secondary<<endl;
	myParam<<(int)k1.left<<endl;
	myParam<<(int)k1.right<<endl;
	myParam<<(int)k1.forward<<endl;
	myParam<<(int)k2.primary<<endl;
	myParam<<(int)k2.secondary<<endl;
	myParam<<(int)k2.left<<endl;
	myParam<<(int)k2.right<<endl;
	myParam<<(int)k2.forward<<endl;
	myParam.close();
	cout<<"Saved!"<<endl;
}

string Settings::keyToString(sf::Keyboard::Key k)
{
	switch (k)
	{
		case sf::Keyboard::A:
			return "A";
			break;
		case sf::Keyboard::B:
			return "B";
			break;
		case sf::Keyboard::C:
			return "C";
			break;
		case sf::Keyboard::D:
			return "D";
			break;
		case sf::Keyboard::E:
			return "E";
			break;
		case sf::Keyboard::F:
			return "F";
			break;
		case sf::Keyboard::G:
			return "G";
			break;
		case sf::Keyboard::H:
			return "H";
			break;
		case sf::Keyboard::I:
			return "I";
			break;
		case sf::Keyboard::J:
			return "J";
			break;
		case sf::Keyboard::K:
			return "K";
			break;
		case sf::Keyboard::L:
			return "L";
			break;
		case sf::Keyboard::M:
			return "M";
			break;
		case sf::Keyboard::N:
			return "N";
			break;
		case sf::Keyboard::O:
			return "O";
			break;
		case sf::Keyboard::P:
			return "P";
			break;
		case sf::Keyboard::Q:
			return "Q";
			break;
		case sf::Keyboard::R:
			return "R";
			break;
		case sf::Keyboard::S:
			return "S";
			break;
		case sf::Keyboard::T:
			return "T";
			break;
		case sf::Keyboard::U:
			return "U";
			break;
		case sf::Keyboard::V:
			return "V";
			break;
		case sf::Keyboard::W:
			return "W";
			break;
		case sf::Keyboard::X:
			return "X";
			break;
		case sf::Keyboard::Y:
			return "Y";
			break;
		case sf::Keyboard::Z:
			return "Z";
			break;
		case sf::Keyboard::Left:
			return "Left";
			break;
		case sf::Keyboard::Right:
			return "Right";
			break;
		case sf::Keyboard::Up:
			return "Up";
			break;
		case sf::Keyboard::Down:
			return "Down";
			break;
		case sf::Keyboard::LControl:
			return "LControl";
			break;
		case sf::Keyboard::LShift:
			return "LShift";
			break;
		case sf::Keyboard::RControl:
			return "RControl";
			break;
		case sf::Keyboard::RShift:
			return "RShift";
			break;
		case sf::Keyboard::Space:
			return "Space";
			break;
		case sf::Keyboard::Tab:
			return "Tab";
			break;	
		case sf::Keyboard::LSystem:
			return "LSystem";
			break;
		default:
			return "Unknown";
			break;
	}
}
