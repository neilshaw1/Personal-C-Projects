#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include<string>
using namespace std;
int rollDice();
int getWager(int money);
void playerTurn(int money, int &wager, bool &bust, int &total, int &houseRoll);
void houseTurn(int houseRoll, bool & bust, int &total);

int main(){
	int pMoney,pWager,pTotal,pHouseRoll,hTotal;
	bool pBust = false;
	bool hBust = false;
	string again;
	pMoney=101;
	srand(time(0));
	do{
		playerTurn(pMoney, pWager, pBust, pTotal, pHouseRoll);
		houseTurn(pHouseRoll,hBust,hTotal);
		if (!pBust && !hBust){//this entire thing al the way up to the next ======= is the area that tests if the user winds. 
			//if the user and house do not bust, then the values need to be compared
			if (pTotal>hTotal){
				cout<<"You win the round! \nYou win $"<<pWager<<"!\n";
				pMoney+=pWager;
			}
			else if (hTotal>pTotal){
				cout<<"You lose the round. \nYou lose $"<<pWager<<".\n";
				pMoney-=pWager;
			}
			else{
				cout<<"You tied (pushed) with the house. \nYou do not gain or lose any money.\n";
			}
		}
		else if (hBust && !pBust){//if the house busts and the player does not, then there is no need to compare values, as the player automatically wins
			cout<<"You win the round! \nYou win $"<<pWager<<"!\n";
			pMoney+=pWager;
		}
		else if (pBust && !hBust){//if the house does not busts and the player does, then there is no need to compare values, as the player automatically loses
			cout<<"You lose the round. \nYou lose $"<<pWager<<".\n";
			pMoney-=pWager;
		}
		else{
			cout<<"You tied (pushed) with the house. \nYou do not gain or lose any money.\n"; //if the values are equal, then there is a tie
		}
		
		if (pMoney<=0){//this sees if you lost all your money and it will end the game if you do
			cout<<"You lost all your money.";
			break;
		}
		cout<<"================================================\n";
		cout<<"You have $"<<pMoney<<" left.\n";
		cout<<"Do you want to play again (y/n): ";
		getline(cin, again);
		while (again != "y" && again != "n" && again != "Y" && again != "N"){//tests for invalid answers
			cout<<"Invalid answer.\n";
			cout<<"Do you want to play again (y/n): ";
			getline(cin, again);
		}
		//resets all values so that the code will work properly. Some parts may not be needed, but it is just helpful to keep for organization's sake
		pBust = false;
		hBust = false;
		pHouseRoll = 0;
		pTotal = 0;
		hTotal = 0;
	}while(again=="y" || again=="Y");
	return 0;
}

int rollDice(){//Step 1 
	int roll;
	roll = rand() % (13) + 1;
	switch (roll){//uses swtich case to make the probability of getting a 10 higher
		case 1:
			return 2;
		case 2:
			return 3;
		case 3:
			return 4;
		case 4:
			return 5;
		case 5:
			return 6;
		case 6:
			return 7;
		case 7:
			return 8;
		case 8:
			return 9;
		case 9:
			return 10;
		case 10:
			return 10;
		case 11:
			return 10;
		case 12:
			return 10;
		case 13:
			return 11;
	}
}

int getWager(int money){//Step 2
	int wager;
	cout<<"================================================\n";
	cout<<"Enter your wager: ";
	cin>>wager;
	cin.ignore();//deletes whitespace
	while (wager<=0||wager>money){//testing if the wager is negative more more than the user's current amount of money
		cout<<"You can only enter a positive integer less than or equal to $"<<money<<".\n";
		cout<<"Enter your wager: ";
		cin>>wager;
		cin.ignore();
	}
	cout<<"================================================\n";
	return wager;
}

void playerTurn(int money, int &wager, bool &bust, int &total, int &houseRoll){
	string hitStand;
	hitStand="h";
	wager = getWager(money);//asks user for wager
	houseRoll = rollDice();
	total = rollDice() + rollDice();//Step 3 
	cout<<"The house's first roll -> "<< houseRoll <<endl;
	while(hitStand=="h" || hitStand=="H"){
		if (total>=22){//sees of the user busted
			cout<<"You busted with a total of "<<total<<endl;
			bust=true;
			break;
		}
		cout<<"You have a total of "<<total<<".\nDo you want to hit or stand (h/s): ";
		getline(cin,hitStand);
		while(hitStand != "h" && hitStand != "H" && hitStand != "s" && hitStand != "S"){//tests for invalid answers
			cout<<"Invalid answer.\n";
			cout<<"Do you want to hit or stand (h/s): ";
			getline(cin, hitStand);
		}
		if (hitStand=="h" || hitStand=="H"){
			total+=rollDice();
		}
		else if (hitStand == "s" || hitStand=="S"){
			break;//uses break to leave the while loop when an s is inputted
		}
		cout<<"================================================\n";
	}
	if (!bust){
		cout<<"You stood with a total of "<<total<<endl;
	}
}

void houseTurn(int houseRoll, bool & bust, int &total){
	char repeat = 'y';
	total=houseRoll+rollDice();
	cout<<"================================================\n";
	while(repeat=='y'){
		if (total>=22){
			cout<<"================================================\n";
			cout<<"The house busted with a total of "<<total<<endl;
			bust=true;
			break;
		}
		cout<<"The house has a total of "<<total<<".\n";
		if (total<17){//allows the house to hit if it has a value lower than 17
			total+=rollDice();
			cout<<"The house chooses to hit.\n";
		}
		else{
			cout<<"================================================\n";
			cout<<"The house chooses to stand with a total of "<<total<<endl;
			repeat='n';//when the house gets a value between 17 and 21, it stands
		}
	}
}
