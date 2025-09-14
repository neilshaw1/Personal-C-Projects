#include<iostream>
using namespace std;
void Input(int A[], int &size){
		do{
			cout<<" Enter the number of the elements >=20: ";
			cin>>size;
		}while(size < 20);
		cout<<"Enter the elements "<<endl;
		for (int i =0; i<size;i++){
			cin>>A[i];
		} 	
}

int linearSearch(int A[], int size, int key)
{
    int count = 0;
	for (int i = 0; i < size; i++){
        count++;
		if (key == A[i]){
            return count;
    	}
	}
    return -1;
}

int binarySearch(int A[], int n, int key){
	int mid, lbound = 0, ubound = n-1, count = 0;
	bool found = false;

	while (!found && lbound <= ubound){
		count++;
		mid = (lbound + ubound)/2;
		if(key < A[mid])
			ubound = mid - 1;
		else if (key > A[mid])
			lbound = mid +1;
		else 
			found = true;
	}
	if(found)
		return count;
	else 
		return -1;
}

int main(){
	int arr[]={}, size, key;
	Input(arr, size);
	cout << "What do you want to search for: ";
	cin >> key;
	cout<<"Linear Search took " << linearSearch(arr, size, key) << " comparisons.\n";
	cout<<"Binary Search took " << binarySearch(arr, size, key) << " comparisons.\n";
}
