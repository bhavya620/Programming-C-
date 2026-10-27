#include <iostream>
using namespace std;

int main() {
    int balance;

    cout << "Enter balance: ";

    while (!(cin >> balance) || balance < 0) {
        cout << "Enter a valid balance: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    cout << "Balance: Rs " << balance << ".00" << endl;

    return 0;
}