#include<iostream>
using namespace std;
void Count(string str)
{
	int upper = 0, lower = 0, sentences = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			upper++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			lower++;
		else if (str[i]=='.'|| str[i]=='?' || str[i]=='!')
			sentences++;
	}
	cout << "Upper case letters: " << upper << endl;
	cout << "Lower case letters : " << lower << endl;
	cout << "Number of sentences: " << sentences << endl;
}
int main()
{
	string str;
	cout<<"Enter a string: ";
	getline(cin,str);
	Count(str);
	return 0;
}
