#include <iostream>
using namespace std;
double pow(double b, int p) {
    if (p == 0) {
        return 1;
    } else {
        return b * pow(b, p-1);
    }
}
int main() {
    double base = 2;
    int power = 5;
    double result = pow(base, power);
    cout << base << " raised to the power of " << power << " is " << result << ".";
    return 0;
}
