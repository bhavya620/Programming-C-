#include <iostream>
using namespace std;

bool canTravel(int balance, int fare) {
    return balance - fare >= 50;
}

class SmartCard {
public:
    int balance;

    SmartCard(int b) {
        balance = b;
    }

    void travel(int fare) {
        if (balance - fare >= 50) {
            balance = balance - fare;
            cout << "Travel allowed" << endl;
        } else {
            cout << "Travel denied" << endl;
        }
    }
};

int main() {
    int b = 100;

    if (canTravel(b, 20))
        b = b - 20;

    cout << "Procedural balance: " << b << endl;

    SmartCard c(100);
    c.travel(20);

    cout << "OOP balance: " << c.balance << endl;

    return 0;
}