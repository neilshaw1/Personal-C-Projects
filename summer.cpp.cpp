#include<iostream>
using namespace std;
int main(){
	int month;
	cout<<"Enter a number between 1 and 12, inclusive: ";
	cin>>month;
	
	switch (month){
		case 1:
			cout<<"Not Summer";
			break;
		case 2:
			cout<<"Not Summer";
			break;
		case 3:
			cout<<"Not Summer";
			break;
		case 4:
			cout<<"Not Summer";
			break;
		case 5:
			cout<<"Not Summer";
			break;
		case 6:
			cout<<"June";
			break;
		case 7:
			cout<<"July";
			break;
		case 8:
			cout<<"August";
			break;
		case 9:
			cout<<"Not Summer";
			break;
		case 10:
			cout<<"Not Summer";
			break;
		case 11:
			cout<<"Not Summer";
			break;
		case 12:
			cout<<"Not Summer";
			break;
		default:
			cout<<"Your input is out of range";
	}
}
