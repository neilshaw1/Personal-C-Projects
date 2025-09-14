#include<iostream>
#include<cctype>
using namespace std;
int main(){
	int num;
	char repeat;
	do{
		cout<<"Enter a number: ";
		cin>>num;
		int sum=sumdigits(num);
		sum <<endl;
		cout<< "Sum of digits in number 457 = "<<sumdigits (457) <<endl;
		if(sumdigits (536) 2 ==0)
		cout<<"sum of digits in "<<"536 = "<<sumdigits (536) << " is even. "<<endl;
		else
		cout<<"sum of digits in "<<"536 = "<<<sumdigits (536) << " is odd. "<<endl;
		cout<<"Do you want to repeat (y/Y for yes): ";
		cin>>repeat;
		repeat=toupper(repeat);
	}while(repeat== 'Y');
	
	int sumdigits(int n){
		int s=0; 
		while(n>0){
			s += n%10;
			n/=10
		}
		return s;
}
}
