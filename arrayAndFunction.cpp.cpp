#include<iostream>
#include<string>
using namespace std;

string lookupName(string targetName, string names[], string phoneNumbers[], int size){
	for(int i=0;i<size;i++){
		string tempName = names[i];
		if (targetName == tempName){
			return phoneNumbers[i];
		}
	}
	cout<<"Name not found\n";
	return 0;
}

int main()
{
	string names[] = {"Michael Myers", "Ash William", "Jack Torrance", "Freddy Krueger"};
	string phoneNumbers[]= {"333-8000", "333-2323", "333-6150", "339-7970"};
	string targetName, targetPhone;
	string c;
	do{
		cout << "Enter a name to find the corresponding phone number: ";
		getline(cin,targetName);
		targetPhone = lookupName(targetName, names, phoneNumbers, 4);
		if(targetPhone != "0")
			cout << "The number is: " << targetPhone << endl;
		cout << "Do you want to look up another name (y/n)? ";
		cin >> c;
		cin.ignore();
	}while(c == "y");
	return 0;
}


