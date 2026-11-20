#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string registration;
    double dailyRate;
    bool rented = false;
public:
    Vehicle(string reg, double rate)
        : registration(reg), dailyRate(rate) {}
    virtual double charge(int days) const = 0;
    virtual string type() const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            cout << registration << " rented\n";
        } else {
            cout << registration << " is already rented\n";
        }
    }

    void returnVehicle(int daysLate = 0) {
        if (rented) {
            cout << registration << " returned; late fee: Rs "
                 << daysLate * 100 << '\n';
            rented = false;
        } else {
            cout << registration << " was not rented\n";
        }
    }

    virtual void display(int days) const {
        cout << type() << " " << registration
             << " | Rental charge for " << days << " day(s): Rs "
             << charge(days) << '\n';
    }
    virtual ~Vehicle() = default;
};

class Bicycle : public Vehicle {
public:
    Bicycle(string reg, double rate) : Vehicle(reg, rate) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Bicycle"; }
};

class MotorVehicle : public Vehicle {
protected:
    double fuelOrCharge;
    string serviceDue;
public:
    MotorVehicle(string reg, double rate, double level, string due)
        : Vehicle(reg, rate), fuelOrCharge(level), serviceDue(due) {}
};

class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string reg, double rate, double fuel, string due)
        : MotorVehicle(reg, rate, fuel, due) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Two-wheeler"; }
};

class Car : public MotorVehicle {
protected:
    int seats;
public:
    Car(string reg, double rate, double fuel, string due, int s)
        : MotorVehicle(reg, rate, fuel, due), seats(s) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Car"; }
};

class ElectricCar : public Car {
    double batteryKWh;
    double ratePerKWh;
public:
    ElectricCar(string reg, double rate, double fuel, string due,
                int s, double battery, double kwhRate)
        : Car(reg, rate, fuel, due, s),
          batteryKWh(battery), ratePerKWh(kwhRate) {}
    double charge(int days) const override {
        return dailyRate * days + batteryKWh * ratePerKWh;
    }
    string type() const override { return "Electric car"; }
};

// Added type: existing Vehicle and fleet code do not need modification.
class ElectricBus : public Vehicle {
    int capacity;
public:
    ElectricBus(string reg, double rate, int seats)
        : Vehicle(reg, rate), capacity(seats) {}
    double charge(int days) const override { return dailyRate * days; }
    string type() const override { return "Electric bus"; }
    void display(int days) const override {
        cout << type() << " " << registration << " (" << capacity
             << " seats) | Rental charge for " << days
             << " day(s): Rs " << charge(days) << '\n';
    }
};

int main() {
    vector<unique_ptr<Vehicle>> fleet;
    fleet.push_back(make_unique<Bicycle>("BI-101", 100));
    fleet.push_back(make_unique<TwoWheeler>("TW-202", 250, 8, "2026-12-01"));
    fleet.push_back(make_unique<Car>("CA-303", 1500, 40, "2026-12-10", 5));
    fleet.push_back(make_unique<ElectricCar>("EV-404", 1800, 80,
                                             "2026-12-15", 5, 50, 8));
    fleet.push_back(make_unique<ElectricBus>("EB-505", 5000, 30));

    cout << "Fleet charges:\n";
    for (const auto& v : fleet) v->display(2);

    cout << "Rental operations:\n";
    fleet[0]->rent();
    fleet[0]->returnVehicle(2);
    fleet[0]->rent();
    fleet[0]->returnVehicle();

    return 0;
}
