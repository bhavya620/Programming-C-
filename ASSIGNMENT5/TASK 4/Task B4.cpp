
#include <iostream>
#include <string>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual string type() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
public:
    double total() const override {
        return 1700;
    }

    string type() const override {
        return "OP";
    }
};

class InPatient : public Bill {
public:
    double total() const override {
        return 47500;
    }

    string type() const override {
        return "IP";
    }
};

// New bill type
class DayCare : public Bill {
public:
    double total() const override {
        return 25000;
    }

    string type() const override {
        return "DayCare";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() = default;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }
};

// New payer
class Corporate : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total() * 0.80;
    }
};

int main() {
    Bill* b = new DayCare();

    Payer* p = new Corporate();

    cout << "Bill Type: " << b->type() << '\n';
    cout << "Bill Amount: " << b->total() << '\n';
    cout << "Corporate Covered: "
         << p->amountCovered(*b) << '\n';

    delete p;
    delete b;

    return 0;
}
S