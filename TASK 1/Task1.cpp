#include <iostream>
using namespace std;

class SmartCard {
public:
    int balance;
};

class Passenger {
public:
    string name;
};

int main() {
    SmartCard c;
    Passenger p;

    c.balance = 100;
    p.name = "Bhavya";

    cout << "Passenger: " << p.name << endl;
    cout << "Balance: Rs " << c.balance << endl;

    return 0;
}