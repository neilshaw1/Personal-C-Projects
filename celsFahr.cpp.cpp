#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
float celsius,fahrenheit;
fahrenheit=0;
celsius=(((fahrenheit-32)*5)/9);

cout<<fixed<<setprecision(1);
cout<<left<<setw(15)<<"Fahrenheit"<<left<<setw(15)<<"Celsius"<<endl;
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;

fahrenheit+=20;
celsius=(((fahrenheit-32)*5)/9);
cout<<left<<setw(15)<<static_cast<int>(fahrenheit)<<left<<setw(15)<<celsius<<endl;
}
