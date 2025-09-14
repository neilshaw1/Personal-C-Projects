#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, x1, x2, discriminant;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "The equation has two solutions, "<<x1<<" and "<<x2;
    }
    else if (discriminant == 0) {
        x1 = -b/(2*a);
        cout << "The equation has one solution, " << x1 << endl;
    }
    else {
    	cout<<"This equation has no real solutions"; 
    }

    return 0;
}
