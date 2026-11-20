
#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
using namespace std;

class Guard {
public:
    Guard() {
        cout << "Object created\n";
    }

    ~Guard() {
        cout << "Object destroyed\n";
    }
};

void validate(double amount) {
    if (amount < 0)
        throw invalid_argument("Negative charge");

    if (amount > 1000000)
        throw out_of_range("Claim exceeds limit");

    cout << "Valid amount\n";
}

int main() {
    Guard g;

    try {
        validate(-500);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    try {
        validate(2000000);
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    try {
        double amount = stod("hello");
        cout << amount;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << '\n';
    }

    try {
        size_t n = static_cast<size_t>(-1);
        int* arr = new int[n];
        delete[] arr;
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed\n";
    }
    catch (const exception& e) {
        cout << "Allocation error: " << e.what() << '\n';
    }

    return 0;
}
