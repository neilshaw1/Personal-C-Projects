#include <iostream>
using namespace std;

int main() {
  
  int i = 0;
  int square = 0;
  
  while ( i <= 50) {
    square = i*i;
    cout << i << "     " << square << "\n";
    i = i + 1; 
  }

  return 0; 
} 
