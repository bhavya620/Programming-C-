#include <iostream>
using namespace std;

int fare(int zone, bool peak) {
    int f;

    switch (zone) {
        case 1: f = 1000; break;
        case 2: f = 2000; break;
        case 3: f = 3000; break;
        default: return -1;
    }

    if (peak)
        f = f + f * 20 / 100;

    return f;
}

int main() {
    int balance = 10000;
    int zones[] = {1, 3, 2};
    bool peak[] = {false, true, false};

    for (int i = 0; i < 3; i++) {
        int f = fare(zones[i], peak[i]);

        if (f == -1)
            cout << "Invalid zone" << endl;
        else if (balance - f >= 5000) {
            balance = balance - f;
            cout << "Fare: Rs " << f / 100.0 << endl;
        } else {
            cout << "Travel denied" << endl;
        }

        cout << "Balance: Rs " << balance / 100 << endl;
    }

    return 0;
}