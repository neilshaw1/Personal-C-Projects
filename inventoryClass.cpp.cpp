#include <iostream>
using namespace std;

class Inventory {
private:
    int itemNumber;
    int quantity;
    double cost;

public:
    Inventory() {
        itemNumber = 0;
        quantity = 0;
        cost = 0.0;
    }

    
    Inventory(int itemNo, int qty, double itemCost) {
        itemNumber = itemNo;
        quantity = qty;
        cost = itemCost;
    }

    
    void setItemNumber(int itemNo) {
        itemNumber = itemNo;
    }

    void setQuantity(int qty) {
        quantity = qty;
    }

    void setCost(double itemCost) {
        cost = itemCost;
    }

    int getItemNumber() {
        return itemNumber;
    }

    int getQuantity() {
        return quantity;
    }

    double getCost() {
        return cost;
    }

    double getTotalCost() {
        return quantity * cost;
    }
};

int main() {
    Inventory item1; 
    Inventory item2(101, 10, 5.5);

    cout << "Item 1 - Item Number: " << item1.getItemNumber() << ", Quantity: " << item1.getQuantity() << ", Cost: $" << item1.getCost() << ", Total Cost: $" << item1.getTotalCost() << endl;
    cout << "Item 2 - Item Number: " << item2.getItemNumber() << ", Quantity: " << item2.getQuantity() << ", Cost: $" << item2.getCost() << ", Total Cost: $" << item2.getTotalCost() << endl;

    return 0;
}
