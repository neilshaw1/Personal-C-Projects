#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;
int main ()
{
    int choice = 0,num1, num2, response, result;
    unsigned seed = time(0);
    srand(seed);
    do
    {
		num1=1+rand()%100;
		num2=1+rand()%100;
        cout<<"=================================\nMath Tutor Menu:\n";
        cout<<"1.Addition\n";
        cout<<"2.Subtraction\n";
        cout<<"3.Multiplication\n";
        cout<<"4.Quit\n";
        do
        {
            cout<<"Select 1, 2, 3, or 4: ";
            cin>> choice;
        }while((choice<1) || (choice>5));
        switch (choice)
        {
            case 1:
            {
                cout<<"Here is an addition problem: " <<endl;
                cout<< num1 << "+" << num2 << "= " <<endl;
                cin>> response;
                result= num1 + num2;
                if (response== result)
                    cout<< "You got the answer right.\n";
                else
                    cout<<"Your answer is incorrect. The correct answer is:"<<result<<endl;
                break;
            }

            case 2:
            {
                cout<< "Here is a subtraction problem: " <<endl;
                cout<< num1 << "-" << num2 << "= " <<endl;
                cin>> response;
                result= num1 - num2;
                if (response== result)
                    cout<<"You got the answer right\n";
                else
                    cout<<"Your answer is incorrect. The correct answer is:"<<result<<endl;
                break;
            }

            case 3:
            {
                cout<<"Here is a multiplication problem: " <<endl;
                cout<< num1 << "*" << num2 << "= " <<endl;
                cin>> response;
                result= num1 * num2;
                if (response==result)
                    cout<<"You got the answer right.\n";
                else
                    cout<<"Your answer is incorrect. The correct answer is:"<<result<<endl;
                break;
            }
        }

    } while(choice!=4);
    return 0;
}
