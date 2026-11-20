
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OP : public Bill {
public:
    double total() const override {
        return 1700;
    }
};

struct SimpleBill {
    int type;
    double amount;
};

int main() {
    vector<int> sizes = {
        1000, 1000000, 10000000
    };

    for (int n : sizes) {
        vector<Bill*> bills;
        vector<SimpleBill> simple;

        for (int i = 0; i < n; i++) {
            bills.push_back(new OP());
            simple.push_back({1, 1700});
        }

        volatile double sum1 = 0;
        volatile double sum2 = 0;

        auto start1 = high_resolution_clock::now();

        for (Bill* b : bills)
            sum1 += b->total();

        auto end1 = high_resolution_clock::now();

        auto start2 = high_resolution_clock::now();

        for (const auto& b : simple) {
            if (b.type == 1)
                sum2 += b.amount;
        }

        auto end2 = high_resolution_clock::now();

        cout << "\nBills: " << n;

        cout << "\nVirtual time: "
             << duration<double, milli>(end1 - start1).count()
             << " ms";

        cout << "\nSwitch time: "
             << duration<double, milli>(end2 - start2).count()
             << " ms\n";

        for (Bill* b : bills)
            delete b;
    }

    return 0;
}
