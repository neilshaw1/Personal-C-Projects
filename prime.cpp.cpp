#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
    for (int a=25; a<=101; a++) 
    {	bool prime=true;    	
        for (int b=2; b<=sqrt(a); b++)
        {
            if (a%b==0) { 
            	prime = false;
                break;
        	}
        }
		if (prime) {
			cout<<a<<endl;
		}
	}
	return 0;
}
