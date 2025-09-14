#include <iostream>
using namespace std;

int main() {
  int num, digit1, digit2, digit3, sum;
  
  cout << "Enter a 3 digit number: ";
  cin >> num;
  
  digit1 = num % 10;
  num = num / 10;
  
  digit2 = num % 10;
  num = num / 10;
  
  digit3 = num;
  
  sum = digit1 + digit2 + digit3;
  
  cout << "The sum of the digits of the number is " << sum << "." << endl;

  return 0;
}
