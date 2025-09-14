#include<iostream>
using namespace std;
void SumCol(int A[][5],int row, int col){
	int sumc;
	for(int i=0;i<col;i++){
		sumc=0;
		for(int j=0;j<row;j++){
			sumc += A[j][i];
		}
		cout << "Sum of elements on column " << i+1 << ":" << sumc << endl;
	}
}

void Display(int arr[][5], int row, int col){
	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < col; j++) { 
			cout << arr[i][j] << " "; 
		} 
		cout << endl; 
	} 
}
int main(){
	int row = 5;
	int col = 5;
	int arr[3][3];
	Display(arr[][], row, col)
}
