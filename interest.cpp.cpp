#include<iostream>
#include<cmath>
using namespace std;

int main()
{
float principal,interestRate,timesCompounded,finalBalance;

cout<<"Initial Balance: $";
cin>>principal;

cout<<"Interest Rate: ";
cin>>interestRate;

cout<<"Times Compounded Annually: ";
cin>>timesCompounded;

finalBalance = principal*pow((static_cast<float>(1.0)+(interestRate/timesCompounded)),timesCompounded);

cout<<"Final Balance: $"<<finalBalance;


}
