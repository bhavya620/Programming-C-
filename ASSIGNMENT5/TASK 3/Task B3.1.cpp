
#include <iostream>
#include <vector>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(double c, double t)
        : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

class InPatient : public Bill {
    double days, rate, surgery;

public:
    InPatient(double d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }
};

struct SimpleBill {
    int type;
    double a, b, c;
};

double switchTotal(const SimpleBill& bill) {
    switch (bill.type) {
        case 1:
            return bill.a + bill.b;

        case 2:
            return bill.a * bill.b + bill.c;

        default:
            return 0;
    }
}

int main() {
    vector<Bill*> bills;

    bills.push_back(new OutPatient(500, 1200));
    bills.push_back(new InPatient(3, 2500, 40000));

    double virtualSum = 0;

    for (Bill* b : bills)
        virtualSum += b->total();

    vector<SimpleBill> simple = {
        {1, 500, 1200, 0},
        {2, 3, 2500, 40000}
    };

    double switchSum = 0;

    for (const auto& b : simple)
        switchSum += switchTotal(b);

    cout << "Virtual Total: " << virtualSum << '\n';
    cout << "Switch Total: " << switchSum << '\n';

    for (Bill* b : bills)
        delete b;

    return 0;
}
