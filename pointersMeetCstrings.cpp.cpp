#include <bits/stdc++.h>
using namespace std;
void reverseString(char* a) {
	int length; 
	char *front, *rear, temp; 
	length = strlen(a); 
	front = a;
	rear = a + length - 1;
	for (int i = 0; i < (length - 1) / 2; i++) { 
		temp = *rear; 
		*rear = *front; 
		*front = temp; 
		front++; 
		rear--; 
	}
}

int main(){	
	char a[1000] = "idontknowwhattowritehere"; 
	cout<<"Input: "<<a<<endl;
	reverseString(a); 
	printf("Output: %s\n", a); 
	return 0; 
} 

