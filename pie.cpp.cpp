#include<iostream>
using namespace std;
void input(int a[], int size){
	cout<<"Enter the number of pies eaten: ";
	for (int i = 0; i<size; i++){
		cin>>a[i];
	} 				
}

void bubbleSort(int a[], int size){
	int temp;
	for (int i =0; i<size-1; i++){
		for(int j = 0; j<size-1-i ; j++){
			if(a[j] > a[j + 1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				
			}
		}
	}
}

int findMode(int a[], int size){
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
	return mode;
}

int main(){
	int size=30;
	int a[size];
	input(a, size);
	bubbleSort(a, size);
	cout<<"Mode: "<<findMode(a, size);
}
