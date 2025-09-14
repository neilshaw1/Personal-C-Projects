#include <iostream>
#include <string>
using namespace std;
class Car {
private:
    int year;
    string make;
    int speed;

public:
    Car(int carYear, string carMake) {
        year = carYear;
        make = carMake;
        speed = 0;
    }

    int getYear() {
        return year;
    }

    string getMake() {
        return make;
    }

    int getSpeed() {
        return speed;
    }

    void accelerate() {
        speed += 5;
    }

    void brake() {
        if (speed >= 5) {
            speed -= 5;
        } else {
            speed = 0;
        }
    }
};

int main() {
    Car myCar(2022, "Toyota");

    myCar.accelerate();
    myCar.accelerate();
    myCar.accelerate();

    cout << "Car Info After Accelerating 3 Times \nYear: " << myCar.getYear() << "\nMake: " << myCar.getMake() << "\nSpeed: " << myCar.getSpeed() << endl << "===================================================" << endl;

    myCar.brake();
    myCar.brake();

    cout << "Car Info After Braking 2 Times \nYear: " << myCar.getYear() << "\nMake: " << myCar.getMake() << "\nSpeed: " << myCar.getSpeed() << endl;

    return 0;
}
