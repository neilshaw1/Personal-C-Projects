#include <iostream>
using namespace std;
int main(){
	int min, max;
	cout << "Enter minimum value : ";
	cin >> min;
	cout << "Enter maximum value : ";
	cin >> max;
	cout << "Choose a number between (and including) " << min << " and "<< max << " : ";
	max++;
	int userNum;
	cin >> userNum;
	cout << endl;
	int compGuess, guessCount = 1;
	compGuess = ( max + min ) / 2;
		while ( userNum != compGuess ){
			cout << "Computer guesses " << compGuess;
			cout << endl;
			cout << "Is your number higher? (y/n) : ";
			char userYesOrNo;
			cin >> userYesOrNo;
			bool numTest;
				if ( userYesOrNo == 'y' ){
						numTest = true;
						min     = compGuess;
					}
				else{
						numTest = false;
						max = compGuess;
					}
                if (numTest){
						compGuess = ( compGuess + max ) / 2;
					}
                else{
						compGuess = ( min + compGuess ) / 2;
					}
			cout << endl;
			guessCount++;
		}
	cout << "Your number is " << compGuess << endl;
	cout << "computer guessed on attempt " << guessCount;
	cout << endl;
	cout << endl;
	}
