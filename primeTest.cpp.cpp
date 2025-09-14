#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
	bool prime=true;    	
	for (int i=2; i<=sqrt(n); i++)
	{
		if (n%i==0) { 
			return false;
		}
	}
	return true;
	}

int main (){
	int n;
	cout<<"Enter an integer: ";
	cin>>n;
	if (isPrime(n))
		cout<<"This is prime.";
	else if (!isPrime(n))
		cout<<"This is not prime.";
}

