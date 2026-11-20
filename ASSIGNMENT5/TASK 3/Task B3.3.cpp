
#include <iostream>
#include <stdexcept>
#include <chrono>
using namespace std;
using namespace chrono;

bool validateReturn(double amount) {
    return amount >= 0;
}

void validateException(double amount) {
    if (amount < 0)
        throw invalid_argument("Invalid amount");
}

int main() {
    const int N = 1000000;

    for (int invalidPercent : {0, 1, 50}) {
        int invalidCount = N * invalidPercent / 100;

        auto start1 = high_resolution_clock::now();

        int valid1 = 0;

        for (int i = 0; i < N; i++) {
            double amount = (i < invalidCount) ? -10 : 100;

            if (validateReturn(amount))
                valid1++;
        }

        auto end1 = high_resolution_clock::now();

        auto start2 = high_resolution_clock::now();

        int valid2 = 0;

        for (int i = 0; i < N; i++) {
            double amount = (i < invalidCount) ? -10 : 100;

            try {
                validateException(amount);
                valid2++;
            }
            catch (const invalid_argument&) {
            }
        }

        auto end2 = high_resolution_clock::now();

        cout << "\nInvalid percentage: "
             << invalidPercent << "%";

        cout << "\nReturn code time: "
             << duration<double, milli>(end1 - start1).count()
             << " ms";

        cout << "\nException time: "
             << duration<double, milli>(end2 - start2).count()
             << " ms";

        cout << "\nValid bills: "
             << valid1 << " " << valid2 << '\n';
    }

    return 0;
}
