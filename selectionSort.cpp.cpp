#include <iostream>
using namespace std;
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int a[], int size) {
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void selectionSort(int a[], int size) {
  for (int j = size-1; j >= 0; j--) {
    int indexOfMaximumNumber = j;
    for (int i = 0; i < j; i++) {
      if (a[i] > a[indexOfMaximumNumber])
        indexOfMaximumNumber = i;
    }
    swap(a[indexOfMaximumNumber], a[j]);
  }
}

int main() {
  int a[] = {30, 5, 70, 2};
  int size = 4;
  selectionSort(a, size);
  cout << "Sorted array: ";
  printArray(a, size);
}
