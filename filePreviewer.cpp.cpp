#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream file("text.txt");
    string line;
    int i = 0, lineCount = 0;
    if (!file.is_open()) {
        cout << "Error opening file!";
        return 1;
    }
    string arr[100]={};
    while (getline(file, line)) {
        arr[i]=line;
        lineCount++;
        i++;
    }
    if (lineCount < 10) {
        for(int j=0; j<lineCount; j++) {
            cout << arr[j] << endl;
        }
        cout << "The entire file has been displayed.";
    }
    file.close();
    return 0;
}
