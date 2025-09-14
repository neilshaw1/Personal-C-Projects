#include<iostream>
#include<cstring>
using namespace std;
void sieveOfEratosthenes(int n)
{
	bool prime[n + 1]=true;
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}
int main()
{
	
	int n = 100;
	cout<<"These are the prime numbers between 2 and "<<n<<endl;
	sieveOfEratosthenes(n);
	return 0;
}

