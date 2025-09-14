#include<iostream>
using namespace std;

int main()
{
	float monthNum;
	
	cout<<"Enter a number between 1-12 (inclusive): ";
	cin>>monthNum;
	
	if (monthNum==1){
		cout<<"January";
	}
	
	else if(monthNum==2){
		cout<<"February";
	}
	
	else if(monthNum==3){
		cout<<"March";
	}
	
	else if(monthNum==4){
		cout<<"April";
	}
	
	else if(monthNum==5){
		cout<<"May";
	}
	
	else if(monthNum==6){
		cout<<"June";
	}
	
	else if(monthNum==7){
		cout<<"July";
	}
	
	else if(monthNum==8){
		cout<<"August";
	}
	
	else if(monthNum==9){
		cout<<"September";
	}
	
	else if(monthNum==10){
		cout<<"October";
	}

	else if(monthNum==11){
		cout<<"November";
	}
	
	else if(monthNum==12){
		cout<<"December";
	}
	
	else{
		cout<<"Invalid Input."
	}
}
