#include <bits/stdc++.h>
using namespace std;
const int MAX = 256;
int findPeakElement(int arr[][MAX], int rows, int columns) {
   for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
         if (i == 0 && j == 0) {
            if (arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j + 1]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (i == 0 && j == columns - 1) {
            if (arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j - 1]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (i == rows - 1 && j == 0) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i][j + 1]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (i == rows - 1 && j == columns - 1) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i][j - 1]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (i == 0) {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i + 1][j]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (i == rows - 1) {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i - 1][j]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (j == 0) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j + 1]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else if (j == columns - 1) {
            if (arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j - 1]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
         else {
            if (arr[i][j] > arr[i][j - 1] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i + 1][j]) {
               cout<<arr[i][j]<<" in location ("<<i<<","<<j<<")\n";
            }
         }
      }
   }
   return 0;
}
int main() {
   int arr[][MAX] = {
      { 7, 2, 3, 8 },
      { 2, 3, 4, 5 },
      { 1, 3, 7, 5 },
      { 1, 2, 6, 6 } };
   int rows = 4, columns = 4;
   findPeakElement(arr, rows, columns);
   return 0;
}
