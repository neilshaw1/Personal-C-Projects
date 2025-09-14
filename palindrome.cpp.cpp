#include<iostream>
using namespace std;
bool palindrome(int n){
	int num1,reverse = 0;
	num1=n;
	for(;n!=0;){
		reverse=reverse*10;
		reverse=reverse+n%10;
		n=n/10;}
	cout<<"Reversed number: "<< reverse << endl;
	if(reverse==num1){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	if (palindrome(num)){
		cout<<"This number is a palindrome";
	}
	else{
		cout<<"This number is not a palindrome";
	}
}
