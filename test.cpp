#include<iostream>
using namespace std;


int function1(){
	int timesCalled = 0;
	timesCalled++;
	return timesCalled;
}

int function2(){ 
	static int timesCalled = 0; 
	timesCalled++;
	return timesCalled;
}


int main(){
	for (int count = 1; count <= 3; count++)
		cout << function1() <<" "<< function2() << endl;
}

