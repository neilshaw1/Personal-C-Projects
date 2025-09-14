#include<iostream>
using namespace std;
int main(){
	int num, reverse = 0;
	cout<<"Input a number to reverse: ";
	cin>>num;
	for(;num!=0;){
		reverse=reverse*10;
		reverse=reverse+num%10;
		num=num/10;}
		cout<<"Reversed number: "<< reverse;
		return 0;
}
