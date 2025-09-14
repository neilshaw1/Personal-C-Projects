#include<iostream>
using namespace std;
int main(){
	int num,sum;
	cout<<"Enter an integer: ";
	cin>>num;
	for (int i = 2; i<=num*2; i+=2){
		cout<<i<<" ";
		sum+=i;
	}
	cout<<"\nSum of even numbers: "<<sum;
	return 0;
}
