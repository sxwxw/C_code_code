#include<iostream>
using namespace std;

class Mammal{
	protected: 
		int itsAge;
		int itsweight;
	public:
		int getAge(){
			return itsAge;
		}
		void setAge(int age){
			itsAge=age;
		}
		int getWeight(){
			return itsweight;
		}
		void setWeight(int Weight){
			itsweight=Weight;
		}
		
};

class Dog:public Mammal{
	private:
		string dogColor;
	public:
		string setColor(string color){
			dogColor = color;
		}
		string getColor(){
			return dogColor;
		}
		Dog(){
			cout<<"hhhh";
		}
		Dog(string name){
			cout<<"��������:"<<name;
		}
		~Dog();
};
Dog::~Dog(){
	cout<<"��������"; 
}
int main(){
	Dog dog;
	dog.setColor("��");
	return 0; 
}
