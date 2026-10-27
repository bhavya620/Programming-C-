#include <iostream>
using namespace std;

int main() {
    int zone, hour, base, total = 0;

    for (int i = 1; i <= 5; i++) {
        cout << "Enter zone (1-3) and hour (0-23): ";
        cin >> zone >> hour;

        if (zone < 1 || zone > 3 || hour < 0 || hour > 23) {
            cout << "Invalid input" << endl;
            continue;
        }

        base = zone * 1000;

        if ((hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20))
            base = base + base * 20 / 100;

        cout << "Fare: Rs " << base / 100.0 << endl;
        total = total + base;
    }

    cout << "Total fare: Rs " << total / 100.0 << endl;

    return 0;
}