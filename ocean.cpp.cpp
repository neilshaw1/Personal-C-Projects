#include<iostream>
using namespace std;

int main()
{
	const float oceanLevelPerYear = 3.1;
	cout<<"The ocean level will rise by "<<(oceanLevelPerYear/10)*20<<" centimeters after 20 years.\n";
	cout<<"The ocean level will rise by "<<((oceanLevelPerYear/10)*20)/2.54<<" inches after 20 years.";
	return 0;
}
