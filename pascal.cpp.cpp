#include <iostream>
using namespace std;

int fact(int n)
{
    int product = 1;
    for (int i = 2; i <= n; i++)
        product = product * i;
    return product;
}

int C(int n, int r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}

void print_pascal(int rowNumber){
	for(int n = 0; n <= rowNumber; n++){
		for(int r = 1; r < rowNumber-n+1; r++)
			cout<<"  ";
		for(int r = 0; r <= n; r++){
			cout<<C(n,r)<<"   "; 
		}
		cout<<endl;
	}
}

int main()
{
	print_pascal(7);
	return 0;
}
