#include<iostream>
using namespace std;
void median(double *a, int size){
	double median = 0;
	if ((size % 2) != 0){
		median = a[size/2];
	}
	else{
		double numerator = (a[(size/2)]+a[(size/2)-1]);
		median = (numerator/2.0);
	}
	cout << "Median: " << median << endl;
}

int main(){
	double a[] = {1, 4, 6, 7, 13, 67};
	int size = 6;
	median(a, size);
}
