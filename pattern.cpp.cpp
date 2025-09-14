#include<iostream> 
#include<cctype> 
using namespace std;

void pattern(int, char);
int main(){
	int num;
	char ch;
	char repeat;
	do{
	cout<<"Enter a number: ";
	cin>>num;
	cout<<"Enter a character: "; 
	cin>>ch;
	pattern(num, ch);
	repeat=toupper(repeat);
	}while(repeat=='Y');
}
	
	void pattern(int n, char x){
		for(int i = 1; i<= n; i++){ 
			for(int j=1; j<=i; j++) 
				cout<<x; 
			cout<<endl;
}}
