#include <iostream>
using namespace std;
void removeNumber(int input[], int index, int &size){
	int i;
	for(i = index; i < size - 1; i++)
		input[i] = input[i + 1];
	size--;
}

void removedup(int input[], int &size, int output[]){
	int number;
	for(int i = 0; i < size; i++){
		number = input[i];
		for(int j = i + 1; j < size; j++){
			if(number == input[j]){
				removeNumber(input, j, size);
				j--;			
			}
		}
	}
	for(int m = 0; m < size; m++){
		output[m]=input[m];
	}
}

int main()
{	
	int inpArraySize;
	cout<<"Enter the size of array: "; 
	cin>>inpArraySize;
	int inpArray[inpArraySize];
	int outArray[inpArraySize];
	cout<<"\nEnter the elements: ";
	for(int i = 0; i < inpArraySize; i++) 
		cin >> inpArray[i];
	removedup(inpArray, inpArraySize, outArray);
	for(int j = 0; j < inpArraySize; j++)
		cout << outArray[j] << ' ';
    return 0;
}
