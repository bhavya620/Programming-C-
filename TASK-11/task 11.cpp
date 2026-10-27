#include <iostream>
using namespace std;

class SmartCard {
public:
    int balance;

    SmartCard(int b) {
        balance = b;
    }

    void travel(int zone, int hour) {
        int fare;

        if (zone < 1 || zone > 3) {
            cout << "Invalid zone" << endl;
            return;
        }

        fare = zone * 1000;

        if ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20))
            fare = fare + fare * 20 / 100;

        if (balance - fare >= 5000) {
            balance = balance - fare;
            cout << "Fare: Rs " << fare / 100.0 << endl;
        } else {
            cout << "Travel denied" << endl;
        }

        cout << "Balance: Rs " << balance / 100.0 << endl;
    }
};

int main() {
    SmartCard c(10000);

    c.travel(1, 7);
    c.travel(3, 18);
    c.travel(2, 12);

    return 0;
}