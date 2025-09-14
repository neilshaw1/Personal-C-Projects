#include<iostream>
using namespace std;
int main(){
	int rows;
	char ch;
	int j;
	j=rows;
	ch='A';
	cout<<"Enter an integer: ";
	cin>>rows;
	cout<<endl;
	if (rows<=26){
		for (int i=1;i<=rows;i++){
			cout<<ch;
			ch+=1;
		}
	}
	else 
	
		cout<<"Input is out of range.";
}

