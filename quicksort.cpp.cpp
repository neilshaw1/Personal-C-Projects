#include <iostream>
#include <string>
using namespace std;
void quicksort(string arr[], int left, int right){
	if (left >= right){
		return;
	}
	string pivot = arr[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j){
		while (arr[i] < pivot){
			i++;
		}
		while (arr[j] > pivot){
			j--;
		}
		if (i <= j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	quicksort(arr, left, j);
	quicksort(arr, i, right);
}
int main() {
	string words[] = {"Russian", "English", "Italian", "Spanish", "Hebrew", "French", "German"};
	int arrSize = sizeof(words) / sizeof(words[0]);
	quicksort(words, 0, arrSize - 1);
	for (int i = 0; i < arrSize; i++) {
		cout << words[i] << " ";
	}
	return 0;
}
