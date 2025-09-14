#include<iostream>
using namespace std;

int main()
{
float usd, won, yuan;
cout<<"Please enter an ammount in USD: ";
cin>>usd;
won = usd * (1/0.00087);
yuan = usd * (1/0.15);
cout<<usd<<" dollars to South Korean Won is "<<won<<".\n";
cout<<usd<<" dollars to Chinese Yuan is "<<yuan<<".\n";
}
