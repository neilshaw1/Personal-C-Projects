#include <iostream>
using namespace std;
int rev(int num, int result) {
    if (num == 0) {
        return result;
    }
    return rev(num / 10, result * 10 + num % 10);
}
int main() {
    int num = 537;
    int reversedNum = rev(num, 0);
    cout << "Reversed number: " << reversedNum;
    return 0;
}
