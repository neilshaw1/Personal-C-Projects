#include <iostream>
using namespace std;

int main() {
	int n, largestNum;
	cout<<"How many numbers do you want to input: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i == 0)
			largestNum = num;
		if (num > largestNum)
			largestNum = num;
  }
  cout << largestNum << endl;
  return 0;
}
/*
#include <iostream>
using namespace std;
int main(){
	int n;
cout << "Enter in how many numbers you would like to input: ";
cin >> n;
double maxNum=-1e308;
for(int i=0;i<n;i++){
	double number;
	cout << "Enter in number " << (i+1) << ":";
	cin >> number;
	if(number > maxNum){
		maxNum = number;
	}
}
cout << "The maximum of the numbers you entered is " << maxNum;
}
*/
