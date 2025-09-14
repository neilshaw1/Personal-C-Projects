#include <bits/stdc++.h> 
using namespace std; 
int binarySearch(string arr[], string x, int n) 
{ 
	int l = 0; 
	int r = n - 1; 
	while (l <= r) { 
		int m = l + (r - l) / 2; 
		int res = -1000; 
		if (x == (arr[m])) 
			res = 0; 
		if (res == 0) 
			return m; 
		if (x > (arr[m])) 
			l = m + 1; 
		else
			r = m - 1; 
	} 

	return -1; 
}
int main(){ 
	string arr[] 
		= { "contribute", "geeks", "ide", "practice" }; 
	string x = "practice"; 
	int n = 4; 
	int result = binarySearch(arr, x, n); 
	if (result == -1) 
		cout << ("Element not present"); 
	else
		cout << ("Element found at index ") << result; 
}
