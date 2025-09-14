#include<iostream>
using namespace std;

int main()
{
float money_spent,money_gained,net_value;
const float number_of_shares=600;
const float original_cost_of_shares=21.77;
const float new_cost_of_shares=16.44;
money_spent=number_of_shares*original_cost_of_shares;
money_gained=new_cost_of_shares*number_of_shares;
net_value=money_spent-money_gained;
cout<<"The total amount paid for the stock is "<<money_spent<<".\n";
cout<<"The total amount recieved from the stock is "<<money_gained<<".\n";
cout<<"The total amount of money lost is "<<net_value<<".\n";
}
