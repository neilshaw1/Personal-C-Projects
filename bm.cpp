#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int sum=0;
int A[][3]={7,3,6,
			2,1,4,
			9,5,8};
for(int i=0;i<3;i++)
{ int T=A[i][i];
A[i][i]=A[i][2-i];
A[i][2-i]=T;
}
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
cout<<setw(4)<<A[i][j];
cout<<endl;
}
}
