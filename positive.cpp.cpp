#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	float num1;
	
	cout<<"Enter a number: ";
	cin>>num1;
	if (num1>=0){
		cout<<"This number is positive and its absolute value is "<<abs(num1)<<".";
	}
	else{
		cout<<"This number is negative and its absolute value is "<<abs(num1)<<".";
	}
	
	cout<<"\nAdios!";
	return 0;
}
