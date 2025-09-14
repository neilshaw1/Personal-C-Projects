#include<iostream>
using namespace std;

int main()
{
int num1, num2, temp1, temp2;
cout<<"Enter a number = ";
cin>>num1;
cout<<"Enter another number = ";
cin>>num2;
temp1 = num1;
temp2 = num2;
num1 = num2;
num2 = temp1;
cout<<"Original Variable1 Value = "<<(temp1)<<endl;
cout<<"Original Variable2 Value = "<<(temp2)<<endl;
cout<<"Updated Variable1 Value = "<<(num1)<<endl;
cout<<"Updated Variable2 Value = "<<(num2)<<endl;
}

