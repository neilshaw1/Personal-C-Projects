#include <iostream>
using namespace std;
int handshake(int n){
	if (n <= 1){
		return 0;
	}
	else{
		return (n - 1) + handshake(n - 1);
	}
}

int main(){
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	cout << "Total number of handshakes with " << n << " persons: " << handshake(n);
	return 0;
}
