
#include <iostream>
using namespace std;
void myFunc(); // Function prototype int main()
int main()
{	int var = 100;
	cout << var << endl;
	myFunc();
	cout << var << endl;
	return 0;
}
// Definition of function myFunc
void myFunc()
{	int var = 50;
	cout << var << endl;
}
