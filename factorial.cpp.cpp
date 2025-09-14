#include <iostream>
using namespace std;
long factorial(int);
int main(){
	int n;
	cout<<"Enter an integer: " ;
	cin>>n;
	factorial(n);}
long factorial(int n) {
	int factorial = 1;
	for (int i = 1; i <= n; i++) {
    	factorial = factorial * i;}
	cout<<factorial;
	return 0;}
