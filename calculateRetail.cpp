#include<iostream>
using namespace std;
double calculateRetail (double, double);

int main ()
{
    double wholeSaleCost, markupPercentage, retailprice;
    cout << "Enter an items wholesale cost: ";
    cin >> wholeSaleCost;
    cout << "Enter an items markup percentage: ";
    cin >> markupPercentage;
    retailprice = calculateRetail(wholeSaleCost, markupPercentage);
    cout << "If an items wholesale cost is $"<< wholeSaleCost<< " and its markup percentage is %"<< markupPercentage<< " , then the item's retail price is $"<< retailprice;
return 0;
}

double calculateRetail(double wholeSaleCost, double markupPercentage)
{
    double retailprice;
    retailprice = wholeSaleCost + (markupPercentage/100* wholeSaleCost );
    return retailprice;
}
