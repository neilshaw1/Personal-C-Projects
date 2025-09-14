#include <iostream>
#include <cstring>
using namespace std;
void selectionSort(string a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}
string* addEntry(string* dynamicArray, int& size, string newEntry) {
    string* newArray = new string[size + 1];
    for (int i = 0; i < size; i++) {
        newArray[i] = dynamicArray[i];
    }
    newArray[size] = newEntry;
    size++;
    delete[] dynamicArray;
    return newArray;
}
string* deleteEntry(string* dynamicArray, int& size, string entryToDelete) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (dynamicArray[i] == entryToDelete) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return dynamicArray;
    }
    string* newArray = new string[size - 1];
    int newIndex = 0;
    for (int i = 0; i < size; i++) {
        if (i != index) {
            newArray[newIndex] = dynamicArray[i];
            newIndex++;
        }
    }
    size--;
    delete[] dynamicArray;
    return newArray;
}
int main() {
    int size = 7;
    string* dynamicArray = new string[size];
    string names[] = {"Googly", "Eyes", "Are", "Amazing", "Change", "My", "Mind"};
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = names[i];
    }

  
    selectionSort(dynamicArray, size);
    cout << "Array sorted alphabetically:\n";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << "\n";
    }

  
    dynamicArray = addEntry(dynamicArray, size, "Floppy");
    selectionSort(dynamicArray, size);
    cout << "\nArray sorted alphabetically after adding 'Floppy':\n";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << "\n";
    }

    dynamicArray = deleteEntry(dynamicArray, size, "Ears");
    cout << "\nArray sorted alphabetically after deleting 'Ears':\n";
    for (int i = 0; i < size; i++) {
        cout << dynamicArray[i] << "\n";
    }
    return 0;
}
