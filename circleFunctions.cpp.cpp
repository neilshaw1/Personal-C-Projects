#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int radius;
cout<<"What is the radius of the circle? ";
cin >> radius;
cout<<"The area of a circle with a radius of "<<(radius)<<" is "<<(pow(radius,2) * 3.14)<<".\n";
cout<<"The circumference of a circle with a radius of "<<(radius)<<" is "<<(2* radius * 3.14)<<".";
}
