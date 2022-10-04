#include<iostream> 
using namespace std;
class Date{
	public:
		int h;
		int m;
		int s;
		int setTime(int,int,int);
};
int Date::setTime(int h,int m,int s){
	int sum = h*60*60+m*60+s;
	return sum;
}
int main()
{	
	Date time1;
	Date time2;
	int h1,m1,s1,h2,m2,s2;
	cin>>h1>>m1>>s1;
	cin>>h2>>m2>>s2;
	int sum1=time1.setTime(h1,m1,s1);
	int sum2=time1.setTime(h2,m2,s2);
	if(sum1>sum2){
		cout<<h1<<"h:"<<m1<<"m:"<<s1<<"s ";
		cout<<h2<<"h:"<<m2<<"m:"<<s2<<"s";
	}else{
		cout<<h2<<"h:"<<m2<<"m:"<<s2<<"s ";
		cout<<h1<<"h:"<<m1<<"m:"<<s1<<"s";
	}
	return 0;
}  
