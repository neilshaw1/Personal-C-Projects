#include<iostream>
using namespace std;

int main()
{
int grade1,grade2,grade3,grade4;


cout<<"Enter your first grade: ";
cin>>grade1;
while (grade1>100 or grade1<0)
{
	cout<<"This grade is not between 0-100. Please enter the grade again: ";
	cin>>grade1;
}


cout<<"Enter your second grade: ";
cin>>grade2;
while (grade2>100 or grade2<0)
{
	cout<<"This grade is not between 0-100. Please enter the grade again: ";
	cin>>grade2;
}


cout<<"Enter your third grade: ";
cin>>grade3;
while (grade3>100 or grade3<0)
{
	cout<<"This grade is not between 0-100. Please enter the grade again: ";
	cin>>grade3;
}


cout<<"Enter your fourth grade: ";
cin>>grade4;
while (grade4>100 or grade4<0)
{
	cout<<"This grade is not between 0-100. Please enter the grade again: ";
	cin>>grade4;
}


cout<<"\nYour grades were: "<<grade1<<" "<<grade2<<" "<<grade3<<" "<<grade4<<endl;
cout<<"your average grade is "<<((grade1+grade2+grade3+grade4)/4);

//I don't know how to check if a variable is not an integer so this code will not work if a character is inputed.
}
