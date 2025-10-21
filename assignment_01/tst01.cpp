#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int T; // The number of test cases
    cin >> T;

    // Set the output formatting for all calculations
    // 'fixed' forces decimal notation (e.g., 0.3 instead of 3e-1)
    // 'setprecision(6)' prints 6 digits after the decimal point
    cout << fixed << setprecision(6);

    for (int i = 0; i < T; i++) {
        string dummy_word; // A variable to store the word "calculate"
        double num1, num2;
        char op;

        // Read the input in the correct order:
        // 1. Read "calculate" into dummy_word
        // 2. Read the first number into num1
        // 3. Read the operator into op
        // 4. Read the second number into num2
        cin >> dummy_word >> num1 >> op >> num2;

        // Perform the correct operation
        if (op == '+') {
            cout << num1 + num2 << endl;
        } else if (op == '-') {
            cout << num1 - num2 << endl;
        } else if (op == '*') {
            cout << num1 * num2 << endl;
        } else if (op == '/') {
            cout << num1 / num2 << endl;
        }
    }
    
    return 0;
}