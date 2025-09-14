#include<iostream>
using namespace std;
int main(){
	int num1,num2,operation;
	cout<<"Enter 2 numbers: ";
	cin>>num1>>num2;
	cout<<"1 -> +:Sum\n2 -> -:Difference\n3 -> *:Product\n4 -> /:Quotient\n5 -> %:Remainder\n";
	cout<<"Enter a number from 1 - 5 according to the operator: ";
	cin>>operation;
	switch (operation){
		case 1: 
			cout << "The sum is "<< num1+num2;
			break;
		case 2:
			cout << "The diffrence is "<< num1-num2;
			break;
		case 3:
			cout << "The Product is "<< num1*num2;
			break;
		case 4:
			cout << "The Quotient is "<< num1/num2;
			break;
		case 5:
			cout << "The Remainder is "<< num1%num2;
			break;
		default: cout << "Invalid operation";
	}
}
