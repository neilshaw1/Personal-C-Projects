#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string fileName, keyString, line;
    int count = 0;
    cout << "Enter the name of the file: ";
    cin >> fileName;
    cout << "Enter the string to search for: ";
    cin >> keyString;
    ifstream file(fileName.c_str());
    if (!file.is_open()) {
        cerr << "Unable to open the file." << endl;
        return 1;
    }
    while (getline(file, line)) {
        if (line.find(keyString) != string::npos) {//I had to do some research to find a function that found the string, since I know Benjamin and I used it once in an in-class activity, so I knew it existed - I just didn't know the sytnax of it. I also did some reserach to find out what was the NULL of the string library (string::npos is the NULL of strings, essentially).        if (line.find(keyString) != string::npos){//I had to do some research to find a function that found the string, since I know Benjamin and I used it once in an in-class activity, so I knew it existed - I just didn't know the sytnax of it. I also did some reserach to find out what was the NULL of the string library (string::npos is the NULL of strings, essentially).
            count++;
        }
    }
    cout << "The string '" << keyString << "' appeared " << count << " times in the file." << endl;
    file.close();

    return 0;
}
