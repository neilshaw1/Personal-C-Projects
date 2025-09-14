#include <iostream>
using namespace std;
string upperCaseIt(string s){
for(int i=0;i<s.length();i++){
if('a' <= s[i] && s[i] <= 'z'){
s[i] = s[i]+65-97;//Wrong
}
}
return s;
}
bool sameString(string s1,string s2){
return (upperCaseIt(s1) == upperCaseIt(s2));
}
int main(){
string s1,s2;
cout << "Enter a string: ";
cin >> s1;
cout << "Enter another string: ";
cin >> s2;
cout << (sameString(s1,s2) ? "The strings are equal" : "The strings are not equal");
}
