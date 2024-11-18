#include <iostream>
using namespace std;

// Function to calculate factorial recursively
unsigned long long factorial(int num) {
    if (num <= 1) return 1;   // Base case: factorial of 0 or 1 is 1
    return num * factorial(num - 1); // Recursive case
}

int main() {
    int num;
    cout << "Enter a number to calculate its factorial: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "The factorial of " << num << " is: " << factorial(num) << endl;
    }

    return 0;
}
