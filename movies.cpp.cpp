#include<iostream>
#include<iomanip>
using namespace std;
double average(double a[], int size){
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];
	cout << "Average: " << (sum / size) << endl;
}
void mode(double a[], int size){
	int numRepeat = 1;
	int modeRepeat = 1;
	int num = a[0];
	int mode = num;
	for (int i=1; i<size; i++){
		if (a[i] == num){
			numRepeat++;
			if (numRepeat > modeRepeat){
				modeRepeat = numRepeat;
				mode = num;
			}
		}
	    else{
			num = a[i];
			numRepeat = 1;
		}
	}
	if (modeRepeat == 1) {
		mode = -1;
	}
	cout << "Mode: " << mode << endl;
}

void median(double a[], int size){
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
	double *movies = NULL;
	int size;
	cout << "Enter number of college students: ";
	cin >> size;
	movies = new double[size];
	for(int i = 0; i < size; i++){
		cout << "Person " << i+1 << ": ";
		cin >> movies[i];
	}
	cout << "================================\n";
	average(movies, size);
	mode(movies, size);
	median(movies, size);
}
