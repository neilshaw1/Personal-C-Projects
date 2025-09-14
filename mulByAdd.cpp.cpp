#include<iostream>
using namespace std;
int main(){
	int num1,num2,sum;
	sum=0;
	cout<<"Enter 2 integers: ";
	cin>>num1>>num2;
	if (num1<=num2){
		while (num1>0){
			sum+=num2;
			num1--;}
	cout<<sum;}
	else{
		while (num2>0){
			sum+=num1;
			num2--;}
	cout<<sum;}
}
