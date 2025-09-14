#include <iostream>
#include<cmath>
using namespace std;
int main(){
	int A[6];
	for(int i=0;i<6;i++){
		A[i]=pow(2,i);
	}
	cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[4]<<" "<<A[5];
}
