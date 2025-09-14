#include<iostream>
using namespace std;

int main()
{
int num1,num2;

cout<<"Enter two integers: ";
cin>>num1;
cin>>num2;
	
if (num1<num2){
	cout<<"The maximum number between "<<num1<<" and "<<num2<<" is "<<num2;
}

if (num1>num2){
	cout<<"The maximum number between "<<num1<<" and "<<num2<<" is "<<num1;
}

if (num1==num2){
	cout<<"The two numbers "<<num1<<" and "<<num2<<" are equal.";
}

cout<<"\nGood bye!";

}
	
