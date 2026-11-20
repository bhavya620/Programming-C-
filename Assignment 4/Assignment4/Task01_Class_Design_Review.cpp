#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Staff {
protected:
    string name;
    int id;
    double basic;
    static constexpr double DA_RATE = 0.42;

public:
    Staff(string n, int i, double b) : name(n), id(i), basic(b) {}
    virtual double pay() const = 0;
    virtual void display() const {
        cout << name << " (ID " << id << "): Rs "
             << pay() << '\n';
    }
    virtual ~Staff() = default;
};

class Professor : public Staff {
    double researchAllowance;
public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), researchAllowance(r) {}
    double pay() const override {
        return basic + basic * DA_RATE + researchAllowance;
    }
};

class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b) : Staff(n, i, b) {}
    double pay() const override {
        return basic + basic * DA_RATE;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;
public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}
    double pay() const override {
        return hours * rate;
    }
    void display() const override {
        cout << name << " (ID " << id << "): Rs "
             << pay() << '\n';
    }
};

int main() {
    vector<unique_ptr<Staff>> staff;
    staff.push_back(make_unique<Professor>("Anita", 101, 50000, 8000));
    staff.push_back(make_unique<LabAssistant>("Bala", 102, 30000));
    staff.push_back(make_unique<GuestFaculty>("Charan", 103, 20, 1000));

    cout << "Payroll:\n";
    double total = 0;
    for (const auto& person : staff) {
        person->display();
        total += person->pay();
    }
    cout << "Total payroll: Rs " << total << '\n';
    return 0;
}
