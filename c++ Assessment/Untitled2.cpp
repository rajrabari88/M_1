#include <iostream>
#include <iomanip>

using namespace std;

// Class to represent a food item
class FoodItem {
public:
    string name;
    double price;

    FoodItem(string n, double p) : name(n), price(p) {}

    void display() {
        cout << setw(20) << left << name << "Price: $" << price << endl;
    }
};

// Class to represent a customer order
class Order {
public:
    FoodItem item;
    int quantity;

    Order(FoodItem i, int q) : item(i), quantity(q) {}

    double calculateTotal() {
        return item.price * quantity;
    }
};

// Function to display menu and get user choice
int displayMenu() {
    cout << "Menu:\n";
    cout << "1. Burger\n";
    cout << "2. Pizza\n";
    cout << "3. Pasta\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

int main() {
    string customerName;
    cout << "Enter your name: ";
    getline(cin >> ws, customerName);

    bool continueOrdering = true;

    while (continueOrdering) {
        // Display menu and get user choice
        int choice = displayMenu();

        // Process user choice using switch case
        switch (choice) {
            case 1: {
                FoodItem burger("Burger", 5.99);
                int quantity;
                cout << "Enter the quantity: ";
                cin >> quantity;
                Order burgerOrder(burger, quantity);

                // Generate Bill
                cout << "\n--- Bill ---\n";
                burgerOrder.item.display();
                cout << "Quantity: " << burgerOrder.quantity << endl;
                cout << "Total: $" << burgerOrder.calculateTotal() << endl;
                break;
            }
            case 2: {
                FoodItem pizza("Pizza", 8.99);
                int quantity;
                cout << "Enter the quantity: ";
                cin >> quantity;
                Order pizzaOrder(pizza, quantity);

                // Generate Bill
                cout << "\n--- Bill ---\n";
                pizzaOrder.item.display();
                cout << "Quantity: " << pizzaOrder.quantity << endl;
                cout << "Total: $" << pizzaOrder.calculateTotal() << endl;
                break;
            }
            case 3: {
                FoodItem pasta("Pasta", 6.99);
                int quantity;
                cout << "Enter the quantity: ";
                cin >> quantity;
                Order pastaOrder(pasta, quantity);

                // Generate Bill
                cout << "\n--- Bill ---\n";
                pastaOrder.item.display();
                cout << "Quantity: " << pastaOrder.quantity << endl;
                cout << "Total: $" << pastaOrder.calculateTotal() << endl;
                break;
            }
            case 4:
                cout << "Thank you, " << customerName << "! Have a nice day!\n";
                continueOrdering = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        // Ask whether the customer wants to continue
        char continueChoice;
        cout << "Do you want to continue? (y/n): ";
        cin >> continueChoice;
        continueOrdering = (continueChoice == 'y' || continueChoice == 'Y');
    }

    return 0;
}

