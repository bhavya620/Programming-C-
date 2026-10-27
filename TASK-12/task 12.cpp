#include <iostream>
using namespace std;

class SmartCard {
public:
    int balance;

    SmartCard(int b) {
        balance = b;
    }

    void travel(int zone, int hour, bool weekend, int pass) {
        int fares[] = {1000, 2000, 3000, 6000};

        if (zone < 1 || zone > 4) {
            cout << "Invalid zone" << endl;
            return;
        }

        if (zone == pass || zone == 2 && pass == 1) {
            cout << "Monthly pass used" << endl;
            return;
        }

        int fare = fares[zone - 1];

        if (weekend)
            fare = fare - fare * 10 / 100;
        else if ((hour >= 8 && hour < 10) ||
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
    SmartCard c(100000);

    c.travel(1, 9, false, 1);
    c.travel(3, 18, false, 1);
    c.travel(4, 12, true, 1);

    return 0;
}