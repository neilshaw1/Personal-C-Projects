#include<iostream>
using namespace std; 

double N;
void popul(double P,double B,double C);
int main() {
    double birth,population,days ; 
    cout<< "Enter the starting number of organisms: ";
    cin >> population;
    while (population < 2) {
        cout << "You can't use a number smaller than 2.\n";
        cout << "Enter the starting number of organisms: ";
        cin >> population;
    }
	cout << "Enter the daily population increase rate: ";
    cin >> birth;
   	while (birth < 0) {
        cout << "You cant use a negative number.\n";
        cout << "Enter the daily population increase rate: ";
        cin >> birth;
    }
	cout << "Enter the number of days they will multiply: ";
	cin >> days;
	while (days < 1) {
    	cout << "You can't use a number smaller than 1.\n";
    	cout << "Enter the number of days they will multiply: ";
    	cin >> days;
	}
	birth *= .01;
    for (int count = 0; count < days; count++) {
        popul(population, birth, count);
        population = N;
    }
    return 0;
}

void popul(double P,double B,double C) {
    N = P + (P * B);
	cout << "The size of the population after " << (C+1) << " days is: " << N << endl;
}
