#include<iostream>
using namespace std;
int main (){
	int num;
	char yn;
	do
	{	cout<<"Enter a number: ";
		cin>>num;
		if (num%5==0){
		cout<<"This number is divisible by 5.\n";
		cout<<"Do you want to continue(y/n)?";
        cin>>yn;
	}
	} while (yn == 'y' || yn == 'Y');
	cout<<"\nEnd";
}
