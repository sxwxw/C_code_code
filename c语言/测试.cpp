#include<iostream>
using namespace std;
class Test{
	int c;
	public:
	intx(int a,int b){
		c =  a-b;
	} 
	printx(){
		cout<< c <<endl;
	}
};
int main(){
	Test x;
	x.intx(300,200);
	x.printx();
	return 0;
} 
