#include<iostream>
using namespace std;

int main()
{
int num1,num2,num3;

cout<<"Enter three integers: ";
cin>>num1;
cin>>num2;
cin>>num3;
	
if ((num1<=num2) && (num1<=num3)){
	cout<<"The minimum number between "<<num1<<", "<<num2<<", and "<<num3<<" is "<<num1;
}

else if ((num2<=num1) && (num2<=num3)){
	cout<<"The minimum number between "<<num1<<", "<<num2<<", and "<<num3<<" is "<<num2;
}

else if ((num3<=num1) && (num3<=num2)){
	cout<<"The minimum number between "<<num1<<", "<<num2<<", and "<<num3<<" is "<<num3;
}
return 0;
}

