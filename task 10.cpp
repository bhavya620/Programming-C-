#include <iostream>
using namespace std;

int main() {
    int n[] = {20000, 500000, 3000000};

    for (int i = 0; i < 3; i++) {
        long long paise = (long long)n[i] * 1000;
        double rupees = n[i] * 10.0;

        cout << "Journeys: " << n[i] << endl;
        cout << "Integer total: Rs " << paise / 100.0 << endl;
        cout << "Decimal total: Rs " << rupees << endl;
    }

    return 0;
}