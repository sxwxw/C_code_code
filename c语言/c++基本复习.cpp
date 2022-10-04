#include <iostream>
#include <cstring> 
#include <string>
using namespace std;

class Base
{
	public:
		double Real,Image;
		Base(){
		};
		Base(double real,double image):Real(real),Image(image){
		};
		friend Base & operator+(Base & p1,Base & p2);
};

Base & operator+(Base & p1,Base & p2){
	Base b;
	b.Real = p1.Real + p2.Real;
	b.Image = p1.Image + p2.Image;
	return b;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
}
int main()
{
	Base b1(10.0,11.0);
	Base b2(13.0,11.0);
	Base b3 = b2 + b1;
	cout<<b3.Real<<endl;
	return 0;
}

