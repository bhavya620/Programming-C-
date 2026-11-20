#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Account {
public:
    double rate() const { return 3.5; } // non-virtual: static binding
    virtual double vrate() const { return 3.5; }
    virtual ~Account() { cout << "Account destroyed\n"; }
};

class SeniorAccount : public Account {
    double* history;
public:
    SeniorAccount() : history(new double[100]{}) {}
    double rate() const { return 4.0; }
    double vrate() const override { return 4.0; }
    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destroyed\n";
    }
};

int main() {
    SeniorAccount s;
    Account* p = &s;
    Account copy = s; // slicing: only Account subobject is copied

    cout << "Non-virtual rate: " << p->rate() << '\n';
    cout << "Virtual rate: " << p->vrate() << '\n';
    cout << "Sliced copy virtual rate: " << copy.vrate() << '\n';

    cout << "Unique pointer fleet:\n";
    vector<unique_ptr<Account>> accounts;
    accounts.push_back(make_unique<Account>());
    accounts.push_back(make_unique<SeniorAccount>());
    for (const auto& a : accounts)
        cout << a->vrate() << '\n';

    cout << "End of main\n";
    return 0;
}
