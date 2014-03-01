#include <iostream>
#include "CandyMath.h"

using namespace std;
using namespace Candy;
int main()
{
	Vector vect1(1,2);
	Vector X = Vector::UNIT_X;
	Vector vect2(0.5,0.5);
	Vector vect3(-4,4);
	cout<<"vect1 : "<<vect1<<endl;
	cout<<"vect2 : "<<vect2<<endl;
	cout<<"vect3 : "<<vect3<<endl;
	cout<<"2*vect1 : "<<(2*vect1)<<endl;
	cout<<"vect2 + vect3 : "<<(vect2+vect3)<<endl;
	cout<<"vect2 /= 2 : "<<(vect2/=2)<<endl;
	cout<<"vect2 /2: "<<(vect2/2)<<endl;
}
