#include <iostream>
#include <string>
using namespace std;
class Date {
private:
    int month;
    int day;
    int year;
    
    string getMonthName(int month) {
        string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return months[month - 1];
    }
    
public:
    Date(int m, int d, int y) : month(m), day(d), year(y) {}
    
    void printDate1() {
        cout << month << "/" << day << "/" << year << endl;
    }
    
    void printDate2() {
        string monthName = getMonthName(month);
        cout << monthName << " " << day << ", " << year << endl;
    }
    
    void printDate3() {
        string monthName = getMonthName(month);
        cout << day << " " << monthName << " " << year << endl;
    }
};

int main() {
    Date date(3, 15, 2013);
    
    date.printDate1();
    date.printDate2();
    date.printDate3();
    
    return 0;
}
