#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    // Prompt user for input
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter second number: ";
    cin >> num2;

    // Prompt user for the operation
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    // Perform the corresponding operation
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error! Division by zero." << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
            break;
    }

    return 0;
}